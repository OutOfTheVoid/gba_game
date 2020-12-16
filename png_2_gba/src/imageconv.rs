
#[allow(dead_code)]
pub fn conv_f32_norm_u8 ( input: f32 ) -> u8
{
	
	if input < 0.0
	{
		0
	}
	else
	{
		
		let finput = ( input * 256.0 ).floor ();
		
		if finput >= 256.0
		{
			255
		}
		else
		{
			finput as u8
		}
		
	}
	
}

#[allow(dead_code)]
pub fn conv_f64_norm_u8 ( input: f64 ) -> u8
{
	
	if input < 0.0
	{
		0
	}
	else
	{
		
		let finput = ( input * 256.0 ).floor ();
		
		if finput >= 256.0
		{
			255
		}
		else
		{
			finput as u8
		}
		
	}
	
}

#[allow(dead_code)]
pub fn conv_4_f32_norm_to_u8 ( input: ( f32, f32, f32, f32 ) ) -> ( u8, u8, u8, u8 )
{
	
	let ( x, y, z, w ) = input;
	
	( conv_f32_norm_u8 ( x ), conv_f32_norm_u8 ( y ), conv_f32_norm_u8 ( z ), conv_f32_norm_u8 ( w ), )
	
}

#[allow(dead_code)]
pub fn conv_3_f32_norm_to_4_u8 ( input: ( f32, f32, f32 ) ) -> ( u8, u8, u8, u8 )
{
	
	let ( x, y, z ) = input;
	
	( conv_f32_norm_u8 ( x ), conv_f32_norm_u8 ( y ), conv_f32_norm_u8 ( z ), 255 )
	
}

#[allow(dead_code)]
pub fn conv_3_f64_norm_to_4_u8 ( input: ( f64, f64, f64 ) ) -> ( u8, u8, u8, u8 )
{
	
	let ( x, y, z ) = input;
	
	( conv_f64_norm_u8 ( x ), conv_f64_norm_u8 ( y ), conv_f64_norm_u8 ( z ), 255 )
	
}

#[allow(dead_code)]
pub fn conv_f32_to_norm_3_u8 ( input: f32 ) -> ( u8, u8, u8 )
{
	
	( conv_f32_norm_u8 ( input ), conv_f32_norm_u8 ( input ), conv_f32_norm_u8 ( input ) )
	
}
