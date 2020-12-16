#[allow(dead_code)]
pub fn blend_rgba_alpha_f32 ( src_a: ( f32, f32, f32, f32 ), src_b: ( f32, f32, f32, f32 ) ) -> ( f32, f32, f32, f32 )
{
	
	let ( r_a, g_a, b_a, a_a ) = src_a;
	let ( r_b, g_b, b_b, a_b ) = src_b;
	let scale_a = 1.0 - a_b;
	
	( scale_a * r_a + a_b * r_b,
	  scale_a * g_a + a_b * g_b,
	  scale_a * b_a + a_b * b_b,
	  a_b + a_a * ( 1.0 - a_b ) )
	
}

#[allow(dead_code)]
pub fn blend_src_rgba_dst_rgb_alpha_f32 ( src_a: ( f32, f32, f32 ), src_b: ( f32, f32, f32, f32 ) ) -> ( f32, f32, f32 )
{
	
	let ( r_a, g_a, b_a ) = src_a;
	let ( r_b, g_b, b_b, a_b ) = src_b;
	let scale_a = 1.0 - a_b;
	
	( scale_a * r_a + a_b * r_b,
	  scale_a * g_a + a_b * g_b,
	  scale_a * b_a + a_b * b_b )
	
}