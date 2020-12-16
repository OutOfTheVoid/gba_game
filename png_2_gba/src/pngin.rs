use std::path::Path;
use std::fs::File;
use std::io::BufReader;
use std::slice;
use std::mem;

use crate::image::ImageData2D;

extern crate png;

#[allow(dead_code)]
pub enum PngData {
	RGB8 (ImageData2D<(u8, u8, u8)>),
	RGBA8 (ImageData2D<(u8, u8, u8, u8)>),
	Greyscale8 (ImageData2D<u8>),
	Greyscale16 (ImageData2D<u16>),
}

#[allow(dead_code)]
pub fn read_png(path: &str) -> Result<PngData, String> {
	let file = match File::open(Path::new(path)) {
		Ok(file) => file,
		Err(error) => {
			return Err(error.to_string());
		}
	};
	let decoder = png::Decoder::new (BufReader::new(file));
	let (info, mut reader) = match decoder.read_info() {
		Ok((info, reader)) => (info, reader),
		Err(error) => {
			return Err(error.to_string());
		}
	};
	match info.color_type {
		png::ColorType::Grayscale => {
			match info.bit_depth {
				png::BitDepth::Eight => {
					let mut out_img = ImageData2D::<u8>::new(info.width, info.height, 0);
					match reader.next_frame(&mut out_img.data) {
						Ok(_) => {
							return Ok(PngData::Greyscale8(out_img));
						},
						Err(error) => {
							return Err(error.to_string());
						}
					}
				},
				png::BitDepth::Sixteen => {
					let mut out_img = ImageData2D::<u16>::new(info.width, info.height, 0);
					match reader.next_frame(
						unsafe {
							slice::from_raw_parts_mut(mem::transmute::<&mut u16, *mut u8>(&mut out_img.data[0]), out_img.data.len() * 2)
						}) {
						Ok(_) => {
							return Ok(PngData::Greyscale16(out_img));
						},
						Err(error) => {
							return Err(error.to_string())
						}
					}
				},
				_ => {
					return Err("unsupported format".to_owned())
				}
			}
		},
		png::ColorType::RGB => {
			match info.bit_depth {
				png::BitDepth::Eight => {
					let mut out_img = ImageData2D::<(u8, u8, u8)>::new(info.width, info.height, (0, 0, 0));
					match reader.next_frame(unsafe { slice::from_raw_parts_mut(mem::transmute::<&mut(u8, u8, u8), *mut u8>(&mut out_img.data[0]), out_img.data.len () * 3)}) {
						Ok(_) => {
							return Ok(PngData::RGB8(out_img));
						},
						Err(error) => {
							return Err(error.to_string());
						}
					}
				},
				_ => { 
					return Err("unsupported format".to_owned())
				}
			}
		},
		png::ColorType::RGBA => {
			match info.bit_depth {
				png::BitDepth::Eight => {
					let mut out_img = ImageData2D::<(u8, u8, u8, u8)>::new (info.width, info.height, (0, 0, 0, 0));
					match reader.next_frame ( unsafe { slice::from_raw_parts_mut ( mem::transmute::<&mut ( u8, u8, u8, u8 ), *mut u8>  ( &mut out_img.data [ 0 ] ), out_img.data.len () * 4 ) } ) {
						Ok(_) => {
							return Ok(PngData::RGBA8(out_img));
						},
						Err(error) => {
							return Err(error.to_string());
						}
					}
				},
				_ => {
					return Err ("unsupported format".to_owned());
				}
			}
		},
		_ => {
			return Err("unsupported format".to_owned())
		}
	}
}

