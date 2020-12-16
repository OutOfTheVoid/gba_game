use std;
use commonmath::*;

/*
TODO:

plane projection, reflection for R2 and R4,
SLERP, NLERP, Angle

*/

pub trait ContainsVec2 <E>
{
	
	fn get_x ( &self ) -> E;
	fn get_y ( &self ) -> E;
	
}

pub trait ContainsVec3 <E>
{
	
	fn get_x ( &self ) -> E;
	fn get_y ( &self ) -> E;
	fn get_z ( &self ) -> E;
	
}

pub trait ContainsVec4 <E>
{
	
	fn get_x ( &self ) -> E;
	fn get_y ( &self ) -> E;
	fn get_z ( &self ) -> E;
	fn get_w ( &self ) -> E;
	
}

#[allow(dead_code)]
pub type Vec2F32 = ( f32, f32 );

#[allow(dead_code)]
pub type Vec3F32 = ( f32, f32, f32 );

#[allow(dead_code)]
pub type Vec4F32 = ( f32, f32, f32, f32 );

#[allow(dead_code)]
impl<T> ContainsVec2 <T> for ( T, T ) where T: Copy
{
	
	fn get_x ( &self ) -> T
	{
		let & ( x, _ ) = self;
		x
	}
	
	fn get_y ( &self ) -> T
	{
		let & ( _, y ) = self;
		y
	}
	
}

#[allow(dead_code)]
impl<T> ContainsVec3 <T> for ( T, T, T ) where T: Copy
{
	
	fn get_x ( &self ) -> T
	{
		let & ( x, _, _ ) = self;
		x
	}
	
	fn get_y ( &self ) -> T
	{
		let & ( _, y, _ ) = self;
		y
	}
	
	fn get_z ( &self ) -> T
	{
		let & ( _, _, z ) = self;
		z
	}
	
}

#[allow(dead_code)]
impl<T> ContainsVec4 <T> for ( T, T, T, T ) where T: Copy
{
	
	fn get_x ( &self ) -> T
	{
		let & ( x, _, _, _ ) = self;
		x
	}
	
	fn get_y ( &self ) -> T
	{
		let & ( _, y, _, _ ) = self;
		y
	}
	
	fn get_z ( &self ) -> T
	{
		let & ( _, _, z, _ ) = self;
		z
	}
	
	fn get_w ( &self ) -> T
	{
		let & ( _, _, _, w ) = self;
		w
	}
	
}

#[allow(dead_code)]
pub fn vec2_zero <T: Copy + Zero> () -> ( T, T )
{
	
	( T::get_zero (), T::get_zero () )
	
}

#[allow(dead_code)]
pub fn vec3_zero <T: Copy + Zero> () -> ( T, T, T )
{
	
	( T::get_zero (), T::get_zero (), T::get_zero () )
	
}

#[allow(dead_code)]
pub fn vec4_zero <T: Copy + Zero> () -> ( T, T, T, T )
{
	
	( T::get_zero (), T::get_zero (), T::get_zero (), T::get_zero () )
	
}

#[allow(dead_code)]
pub fn vec2_as_array <T: Copy> ( a: ( T, T ) ) -> [ T; 2 ]
{
	
	let ( x, y ) = a;
	[ x, y ]
	
}

#[allow(dead_code)]
pub fn vec3_as_array <T: Copy> ( a: ( T, T, T ) ) -> [ T; 3 ]
{
	
	let ( x, y, z ) = a;
	[ x, y, z ]
	
}

#[allow(dead_code)]
pub fn vec4_as_array <T: Copy> ( a: ( T, T, T, T ) ) -> [ T; 4 ]
{
	
	let ( x, y, z, w ) = a;
	[ x, y, z, w ]
	
}

#[allow(dead_code)]
pub fn vec2_add <T> ( a: ( T, T ), b: ( T, T ) ) -> ( T, T )
	where T: std::ops::Add<Output = T> + Copy
{
	
	let ( a_x, a_y ) = a;
	let ( b_x, b_y ) = b;
	
	( a_x + b_x, a_y + b_y )
	
}

#[allow(dead_code)]
pub fn vec3_add <T> ( a: ( T, T, T ), b: ( T, T, T ) ) -> ( T, T, T )
	where T: std::ops::Add<Output = T> + Copy
{
	
	let ( a_x, a_y, a_z ) = a;
	let ( b_x, b_y, b_z ) = b;
	
	( a_x + b_x, a_y + b_y, a_z + b_z )
	
}

#[allow(dead_code)]
pub fn vec4_add <T> ( a: ( T, T, T, T ), b: ( T, T, T, T ) ) -> ( T, T, T, T )
	where T: std::ops::Add<Output = T> + Copy
{
	
	let ( a_x, a_y, a_z, a_w ) = a;
	let ( b_x, b_y, b_z, b_w ) = b;
	
	( a_x + b_x, a_y + b_y, a_z + b_z, a_w + b_w )
	
}

#[allow(dead_code)]
pub fn vec2_subtract <T> ( a: ( T, T ), b: ( T, T ) ) -> ( T, T )
	where T: std::ops::Sub<Output = T> + Copy
{
	
	let ( a_x, a_y ) = a;
	let ( b_x, b_y ) = b;
	
	( a_x - b_x, a_y - b_y )
	
}

#[allow(dead_code)]
pub fn vec3_subtract <T> ( a: ( T, T, T ), b: ( T, T, T ) ) -> ( T, T, T )
	where T: std::ops::Sub<Output = T> + Copy
{
	
	let ( a_x, a_y, a_z ) = a;
	let ( b_x, b_y, b_z ) = b;
	
	( a_x - b_x, a_y - b_y, a_z - b_z )
	
}

#[allow(dead_code)]
pub fn vec4_subtract <T> ( a: ( T, T, T, T ), b: ( T, T, T, T ) ) -> ( T, T, T, T )
	where T: std::ops::Sub<Output = T> + Copy
{
	
	let ( a_x, a_y, a_z, a_w ) = a;
	let ( b_x, b_y, b_z, b_w ) = b;
	
	( a_x - b_x, a_y - b_y, a_z - b_z, a_w - b_w )
	
}

#[allow(dead_code)]
pub fn vec2_multiply_scalar <T> ( x: ( T, T ), a: T ) -> ( T, T )
	where T: Copy + std::ops::Mul<Output = T>
{
	
	let ( x_x, x_y ) = x;
	( x_x * a, x_y * a )
	
}

#[allow(dead_code)]
pub fn vec3_multiply_scalar <T> ( x: ( T, T, T ), a: T ) -> ( T, T, T )
	where T: Copy + std::ops::Mul<Output = T>
{
	
	let ( x_x, x_y, x_z ) = x;
	( x_x * a, x_y * a, x_z * a )
	
}

#[allow(dead_code)]
pub fn vec4_multiply_scalar <T> ( x: ( T, T, T, T ), a: T ) -> ( T, T, T, T )
	where T: Copy + std::ops::Mul<Output = T>
{
	
	let ( x_x, x_y, x_z, x_w ) = x;
	( x_x * a, x_y * a, x_z * a, x_w * a )
	
}

#[allow(dead_code)]
pub fn vec2_multiply_comonent <T> ( a: ( T, T ), b: ( T, T ) ) -> ( T, T )
	where T: Copy + std::ops::Mul<Output = T>
{
	
	let ( a_x, a_y ) = a;
	let ( b_x, b_y ) = b;
	
	( a_x * b_x, a_y * b_y )
	
}

#[allow(dead_code)]
pub fn vec3_multiply_comonent <T> ( a: ( T, T, T ), b: ( T, T, T ) ) -> ( T, T, T )
	where T: Copy + std::ops::Mul<Output = T>
{
	
	let ( a_x, a_y, a_z ) = a;
	let ( b_x, b_y, b_z ) = b;
	
	( a_x * b_x, a_y * b_y, a_z * b_z )
	
}

#[allow(dead_code)]
pub fn vec4_multiply_comonent <T> ( a: ( T, T, T, T ), b: ( T, T, T, T ) ) -> ( T, T, T, T )
	where T: Copy + std::ops::Mul<Output = T>
{
	
	let ( a_x, a_y, a_z, a_w ) = a;
	let ( b_x, b_y, b_z, b_w ) = b;
	
	( a_x * b_x, a_y * b_y, a_z * b_z, a_w * b_w )
	
}

#[allow(dead_code)]
pub fn vec2_dot <T> ( a: ( T, T ), b: ( T, T ) ) -> T
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Add<Output = T>
{
	
	let ( a_x, a_y ) = a;
	let ( b_x, b_y ) = b;
	
	a_x * b_x + a_y * b_y
	
}

#[allow(dead_code)]
pub fn vec3_dot <T> ( a: ( T, T, T ), b: ( T, T, T ) ) -> T
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Add<Output = T>
{
	
	let ( a_x, a_y, a_z ) = a;
	let ( b_x, b_y, b_z ) = b;
	
	a_x * b_x + a_y * b_y + a_z * b_z
	
}

#[allow(dead_code)]
pub fn vec4_dot <T> ( a: ( T, T, T, T ), b: ( T, T, T, T ) ) -> T
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Add<Output = T>
{
	
	let ( a_x, a_y, a_z, a_w ) = a;
	let ( b_x, b_y, b_z, b_w ) = b;
	
	a_x * b_x + a_y * b_y + a_z * b_z + a_w * b_w
	
}

#[allow(dead_code)]
pub fn vec3_cross <T> ( a: ( T, T, T ), b: ( T, T, T ) ) -> ( T, T, T )
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Sub<Output = T>
{
	
	let ( a_x, a_y, a_z ) = a;
	let ( b_x, b_y, b_z ) = b;
	
	( a_y * b_z - a_z * b_y, a_z * b_x - a_x * b_z, a_x * b_y - a_y * b_x )
	
}

#[allow(dead_code)]
pub fn vec2_square_magnitude <T> ( a: ( T, T ) ) -> T
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T>
{
	
	let ( a_x, a_y ) = a;
	
	a_x * a_x + a_y * a_y
	
}

#[allow(dead_code)]
pub fn vec3_square_magnitude <T> ( a: ( T, T, T ) ) -> T
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T>
{
	
	let ( a_x, a_y, a_z ) = a;
	
	a_x * a_x + a_y * a_y + a_z * a_z
	
}

#[allow(dead_code)]
pub fn vec4_square_magnitude <T> ( a: ( T, T, T, T ) ) -> T
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T>
{
	
	let ( a_x, a_y, a_z, a_w ) = a;
	
	a_x * a_x + a_y * a_y + a_z * a_z + a_w * a_w
	
}

#[allow(dead_code)]
pub fn vec2_magnitude <T> ( a: ( T, T ) ) -> T
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T> + Sqrt
{
	
	let ( a_x, a_y ) = a;
	
	( a_x * a_x + a_y * a_y ).sqrt ()
	
}

#[allow(dead_code)]
pub fn vec3_magnitude <T> ( a: ( T, T, T ) ) -> T
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T> + Sqrt
{
	
	let ( a_x, a_y, a_z ) = a;
	
	( a_x * a_x + a_y * a_y + a_z * a_z ).sqrt ()
	
}

#[allow(dead_code)]
pub fn vec4_magnitude <T> ( a: ( T, T, T, T ) ) -> T
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T> + Sqrt
{
	
	let ( a_x, a_y, a_z, a_w ) = a;
	
	( a_x * a_x + a_y * a_y + a_z * a_z + a_w * a_w ).sqrt ()
	
}

#[allow(dead_code)]
pub fn vec2_distance <T> ( a: ( T, T ), b: ( T, T ) ) -> T
	where T: Copy + std::ops::Sub<Output = T> + std::ops::Mul<Output = T> + std::ops::Add<Output = T> + Sqrt
{
	
	vec2_magnitude ( vec2_subtract ( a, b ) )
	
}

#[allow(dead_code)]
pub fn vec3_distance <T> ( a: ( T, T, T ), b: ( T, T, T ) ) -> T
	where T: Copy + std::ops::Sub<Output = T> + std::ops::Mul<Output = T> + std::ops::Add<Output = T> + Sqrt
{
	
	vec3_magnitude ( vec3_subtract ( a, b ) )
	
}

#[allow(dead_code)]
pub fn vec4_distance <T> ( a: ( T, T, T, T ), b: ( T, T, T, T ) ) -> T
	where T: Copy + std::ops::Sub<Output = T> + std::ops::Mul<Output = T> + std::ops::Add<Output = T> + Sqrt
{
	
	vec4_magnitude ( vec4_subtract ( a, b ) )
	
}

#[allow(dead_code)]
pub fn vec2_lerp <T> ( a: ( T, T ), b: ( T, T ), t: T ) -> ( T, T )
	where T: Copy + std::ops::Add<Output = T> + std::ops::Sub<Output = T> + std::ops::Mul<Output = T> + One
{
	
	vec2_add ( vec2_multiply_scalar ( a, t ), vec2_multiply_scalar ( b, T::get_one () - t ) )
	
}

#[allow(dead_code)]
pub fn vec3_lerp <T> ( a: ( T, T, T ), b: ( T, T, T ), t: T ) -> ( T, T, T )
	where T: Copy + std::ops::Add<Output = T> + std::ops::Sub<Output = T> + std::ops::Mul<Output = T> + One
{
	
	vec3_add ( vec3_multiply_scalar ( a, t ), vec3_multiply_scalar ( b, T::get_one () - t ) )
	
}

#[allow(dead_code)]
pub fn vec4_lerp <T> ( a: ( T, T, T, T ), b: ( T, T, T, T ), t: T ) -> ( T, T, T, T )
	where T: Copy + std::ops::Add<Output = T> + std::ops::Sub<Output = T> + std::ops::Mul<Output = T> + One
{
	
	vec4_add ( vec4_multiply_scalar ( a, t ), vec4_multiply_scalar ( b, T::get_one () - t ) )
	
}

#[allow(dead_code)]
pub fn vec2_normalize <T> ( a: ( T, T ) ) -> ( T, T )
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T> + std::ops::Div<Output = T> + Sqrt + One
{
	
	let magnitude = vec2_magnitude ( a );
	vec2_multiply_scalar ( a, T::get_one () / magnitude )
	
}

#[allow(dead_code)]
pub fn vec3_normalize <T> ( a: ( T, T, T ) ) -> ( T, T, T )
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T> + std::ops::Div<Output = T> + Sqrt + One
{
	
	let magnitude = vec3_magnitude ( a );
	vec3_multiply_scalar ( a, T::get_one () / magnitude )
	
}

#[allow(dead_code)]
pub fn vec4_normalize <T> ( a: ( T, T, T, T ) ) -> ( T, T, T, T )
	where T: Copy + std::ops::Add<Output = T> + std::ops::Mul<Output = T> + std::ops::Div<Output = T> + Sqrt + One
{
	
	let magnitude = vec4_magnitude ( a );
	vec4_multiply_scalar ( a, T::get_one () / magnitude )
	
}

#[allow(dead_code)]
pub fn vec2_project <T> ( a: ( T, T ), normal: ( T, T ) ) -> ( T, T )
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Add<Output = T> + std::ops::Div<Output = T>
{
	
	vec2_multiply_scalar ( a, vec2_dot ( a, normal ) / vec2_square_magnitude ( normal ) )
	
}

#[allow(dead_code)]
pub fn vec3_project <T> ( a: ( T, T, T ), normal: ( T, T, T ) ) -> ( T, T, T )
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Add<Output = T> + std::ops::Div<Output = T>
{
	
	vec3_multiply_scalar ( a, vec3_dot ( a, normal ) / vec3_square_magnitude ( normal ) )
	
}

#[allow(dead_code)]
pub fn vec4_project <T> ( a: ( T, T, T, T ), normal: ( T, T, T, T ) ) -> ( T, T, T, T )
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Add<Output = T> + std::ops::Div<Output = T>
{
	
	vec4_multiply_scalar ( a, vec4_dot ( a, normal ) / vec4_square_magnitude ( normal ) )
	
}

#[allow(dead_code)]
pub fn vec3_project_on_plane <T> ( a: ( T, T, T ), plane_normal: ( T, T, T ) ) -> ( T, T, T )
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Add<Output = T> + std::ops::Sub<Output = T> + std::ops::Div<Output = T>
{
	
	vec3_subtract ( a, vec3_project ( a, plane_normal ) )
	
}

#[allow(dead_code)]
pub fn vec3_reflect_off_plane<T> ( a: ( T, T, T ), plane_normal: ( T, T, T ) ) -> ( T, T, T )
	where T: Copy + std::ops::Mul<Output = T> + std::ops::Mul<i32, Output = T> + std::ops::Add<Output = T> + std::ops::Sub<Output = T> + std::ops::Div<Output = T>
{
	
	vec3_subtract ( a, vec3_multiply_scalar ( plane_normal, vec3_dot ( a, plane_normal ) * 2i32 ) )
	
}


//#[allow(dead_code)]
//pub fn vec2_


