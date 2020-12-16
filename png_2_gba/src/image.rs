pub struct ImageData2D <Pixel: Copy> {
	pub data: Box<[ Pixel ]>,
	pub size: (u32, u32),
}

impl<Pixel: Copy> ImageData2D<Pixel> {
	pub fn new (width: u32, height: u32, default: Pixel) -> ImageData2D<Pixel> {
		let data_vec = vec![default; (width * height) as usize];
		ImageData2D {
			data: data_vec.into_boxed_slice (),
			size: (width, height),
		}
	}
	
	#[allow(dead_code)]
	pub fn get_dimentions(&self) -> (u32, u32) {
		self.size
	}
	
	#[allow(dead_code)]
	pub fn borrow_data(&self) -> &[Pixel] {
		& self.data
		
	}
	
	#[allow(dead_code)]
	pub fn borrow_data_mut(&mut self) -> &mut[Pixel] {
		& mut self.data
	}
	
	#[allow(dead_code)]
	pub fn set_pixel (&mut self, position: (u32, u32), value: Pixel) {
		let (x, y) = position;
		let (width, height) = self.size;
		if x > width || y > height {
			return;
		}
		self.data [ ( x + y * width ) as usize ] = value;
	}
	
	#[allow(dead_code)]
	pub fn blend_pixel<SrcPixel>(&mut self, position: (u32, u32), source: SrcPixel, blending: &dyn Fn (Pixel, SrcPixel) -> Pixel) {
		let (x, y) = position;
		let (width, height) = self.size;
		if x > width || y > height {
			return;
		}
		let index = ( x + y * width ) as usize;
		self.data [index] = blending(self.data[ index ], source);
	}
	
	#[allow(dead_code)]
	pub fn get_pixel(&self, position: (u32, u32)) -> Option<Pixel> {
		let (x, y) = position;
		let (width, height) = self.size;
		if x > width || y > height {
			None
		} else {
			Some(self.data[(x + y * width) as usize])
		}
	}
	
	#[allow(dead_code)]
	pub fn get_pixel_default(&self, position: (u32, u32), default_value: Pixel) -> Pixel {
		let (x, y) = position;
		let (width, height) = self.size;
		
		if x > width || y > height {
			default_value
		} else {
			self.data[(x + y * width) as usize]
		}
		
	}
	
	#[allow(dead_code)]
	pub fn clear (&mut self, value: Pixel) {
		let (width, height) = self.size;
		for i in 0 .. ((width * height) as usize) {
			self.data[i] = value;
		}
		
	}
	
	#[allow(dead_code)]
	pub fn image_convert_to<ToPixel: Copy>(&self, converter: &dyn Fn(Pixel) -> ToPixel) -> ImageData2D<ToPixel> {
		let (width, height) = self.size;
		let mut new_image = ImageData2D::<ToPixel>::new(width, height, converter(self.data[0]));
		for i in 1 .. (width * height) as usize {
			new_image.data[i] = converter(self.data[i]);
		}
		return new_image;
	}
}

impl <Pixel: Copy> ImageData2D <Pixel> {
	#[allow(dead_code)]
	pub fn image_effect(& mut self, effect: &dyn Fn(Pixel) -> Pixel) {
		let (width, height) = self.get_dimentions ();
		for i in 1 .. (width * height) as usize {
			self.data[i] = effect(self.data[i]);
		}
	}
}

impl <SrcPixel: Copy> ImageData2D <SrcPixel> {
	#[allow(dead_code)]
	pub fn image_effect_new<DstPixel: Copy>(&self, effect: &dyn Fn(SrcPixel) -> DstPixel) -> ImageData2D<DstPixel> {
		let (width, height) = self.size;
		let mut new_image = ImageData2D::<DstPixel>::new(width, height, effect(self.data[0]));
		for i in 1 .. (width * height) as usize {
			new_image.data[i] = effect(self.data[i]);
		}
		new_image
	}
	
	#[allow(dead_code)]
	pub fn image_effect_new_parametric<DstPixel: Copy, Parameters>(&self, effect: &dyn Fn(SrcPixel, &Parameters) -> DstPixel, params: &Parameters) -> ImageData2D <DstPixel> {
		let (width, height) = self.size;
		let mut new_image = ImageData2D::<DstPixel>::new(width, height, effect(self.data[0], &params));
		for i in 1 .. (width * height) as usize {
			new_image.data[i] = effect(self.data[i], &params);
		}
		new_image
	}
	
	#[allow(dead_code)]
	pub fn image_effect_in_place<DstPixel: Copy>(&self, effect: &dyn Fn(SrcPixel) -> DstPixel, dest: &mut ImageData2D<DstPixel>) -> Result <(), String> {
		let (width, height) = self.size;
		if dest.size != self.size {
			Err("dest image has unequal size".to_owned())
		} else {
			for i in 1 .. (width * height) as usize {
				dest.data[i] = effect(self.data[i]);
			}
			Ok(())
		}
	}
	
	#[allow(dead_code)]
	pub fn image_effect_in_place_parametric<DstPixel: Copy, Parameters>(&self, effect: &dyn Fn(SrcPixel, &Parameters) -> DstPixel, params: &Parameters, dest: &mut ImageData2D<DstPixel>) -> Result<(), String> {
		let (width, height) = self.size;
		if dest.size != self.size {
			Err("dest image has unequal size".to_owned())
		} else {
			for i in 1 .. (width * height) as usize {
				dest.data [ i ] = effect ( self.data [ i ], & params );
			}
			Ok(())
		}
	}
}


