use std::env;
use std::option::Option;
use std::fmt::Write;

mod image;
mod pngin;

use pngin::PngData;
use image::ImageData2D;


fn convert_rbg888_to_gba_format(x: (u8, u8, u8)) -> (u8, u8, u8, bool) {
	let (r, g, b) = x;
	(r >> 3, g >> 3, b >> 3, true)
}

fn convert_rbga8888_to_gba_format(x: (u8, u8, u8, u8)) -> (u8, u8, u8, bool) {
	let (r, g, b, a) = x;
	(r >> 3, g >> 3, b >> 3, a > 127)
}

fn main() {
	
}
