#[allow(dead_code)]
pub fn vec2_swizzle_xx <T: Copy> ( a: ( T, T ) ) -> ( T, T )
{
	
	let ( x, _ ) = a;
	( x, x )
	
}

#[allow(dead_code)]
pub fn vec2_swizzle_yx <T: Copy> ( a: ( T, T ) ) -> ( T, T )
{
	
	let ( x, y ) = a;
	( y, x )
	
}

#[allow(dead_code)]
pub fn vec2_swizzle_yy <T: Copy> ( a: ( T, T ) ) -> ( T, T )
{
	
	let ( _, y ) = a;
	( y, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xxx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, _, _ ) = a;
	( x, x, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xxy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, _ ) = a;
	( x, x, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xxz <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, _, z ) = a;
	( x, x, z )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xyx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, _ ) = a;
	( x, y, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xyy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, _ ) = a;
	( x, y, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xzx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, _, z ) = a;
	( x, z, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xzy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, z ) = a;
	( x, z, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_xzz <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, _, z ) = a;
	( x, z, z )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_yxx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, _ ) = a;
	( y, x, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_yxy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, _ ) = a;
	( y, x, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_yxz <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, z ) = a;
	( y, x, z )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_yyx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, _ ) = a;
	( y, y, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_yyy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( _, y, _ ) = a;
	( y, y, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_zxx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, _, z ) = a;
	( z, x, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_zxy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, z ) = a;
	( z, x, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_zyx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, y, z ) = a;
	( z, y, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_zyy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( _, y, z ) = a;
	( z, y, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_zzx <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( x, _, z ) = a;
	( z, z, x )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_zzy <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( _, y, z ) = a;
	( z, z, y )
	
}

#[allow(dead_code)]
pub fn vec3_swizzle_zzz <T: Copy> ( a: ( T, T, T ) ) -> ( T, T, T )
{
	
	let ( _, _, z ) = a;
	( z, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, _ ) = input;
	( x, x, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( x, x, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( x, x, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( x, x, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( x, x, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( x, x, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, x, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, x, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( x, x, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, x, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( x, x, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, x, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( x, x, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, x, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, x, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xxww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( x, x, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( x, y, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( x, y, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, y, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, y, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( x, y, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( x, y, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, y, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, y, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, y, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, y, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, y, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( x, y, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xywx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, y, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xywy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, y, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xywz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( x, y, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xyww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, y, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( x, z, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, z, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( x, z, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, z, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, z, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, z, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, z, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( x, z, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( x, z, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( x, z, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( x, z, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, z, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, z, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( x, z, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, z, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xzww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, z, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( x, w, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, w, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, w, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( x, w, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, w, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, w, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( x, w, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, w, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, w, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( x, w, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, w, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, w, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( x, w, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( x, w, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( x, w, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_xwww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( x, w, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( y, x, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( y, x, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, x, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, x, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( y, x, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( y, x, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, x, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, x, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, x, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, x, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, x, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( y, x, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, x, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, x, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( y, x, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yxww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, x, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( y, y, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( y, y, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, y, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, y, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, _ ) = input;
	( y, y, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, _ ) = input;
	( y, y, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( y, y, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( y, y, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, y, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( y, y, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( y, y, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, y, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yywx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, y, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yywy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( y, y, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yywz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, y, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yyww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( y, y, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, z, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, z, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, z, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( y, z, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, z, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( y, z, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( y, z, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, z, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( y, z, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( y, z, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( y, z, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, z, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( y, z, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, z, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, z, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_yzww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, z, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, w, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, w, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( y, w, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, w, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, w, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( y, w, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, w, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( y, w, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( y, w, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, w, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, w, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, w, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( y, w, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( y, w, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( y, w, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_ywww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( y, w, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( z, x, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, x, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( z, x, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, x, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, x, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, x, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, x, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( z, x, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( z, x, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, x, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( z, x, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, x, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, x, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( z, x, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, x, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zxww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, x, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, y, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, y, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, y, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( z, y, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, y, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( z, y, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( z, y, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, y, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, y, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( z, y, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( z, y, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, y, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zywx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( z, y, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zywy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, y, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zywz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, y, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zyww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, y, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( z, z, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, z, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( z, z, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, z, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, _ ) = input;
	( z, z, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( z, z, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( z, z, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, z, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, _ ) = input;
	( z, z, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, _ ) = input;
	( z, z, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, _ ) = input;
	( z, z, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( z, z, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, z, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, z, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( z, z, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zzww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( z, z, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, w, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( z, w, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, w, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, w, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( z, w, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, w, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, w, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, w, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, w, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, w, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( z, w, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( z, w, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( z, w, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( z, w, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( z, w, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_zwww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( z, w, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( w, x, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, x, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, x, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( w, x, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, x, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, x, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( w, x, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, x, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, x, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( w, x, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, x, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, x, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( w, x, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, x, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, x, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wxww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( w, x, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, y, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, y, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( w, y, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, y, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, y, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( w, y, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, y, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( w, y, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( w, y, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, y, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, y, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, y, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wywx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, y, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wywy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( w, y, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wywz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, y, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wyww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( w, y, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, z, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( w, z, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, z, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, z, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, z, w ) = input;
	( w, z, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, z, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, z, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, z, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, z, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, z, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( w, z, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( w, z, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, z, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, z, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( w, z, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wzww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( w, z, w, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwxx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( w, w, x, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwxy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, w, x, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwxz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, w, x, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwxw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( w, w, x, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwyx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, y, _, w ) = input;
	( w, w, y, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwyy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( w, w, y, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwyz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, w, y, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwyw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( w, w, y, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwzx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, z, w ) = input;
	( w, w, z, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwzy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, z, w ) = input;
	( w, w, z, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwzz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( w, w, z, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwzw <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( w, w, z, w )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwwx <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( x, _, _, w ) = input;
	( w, w, w, x )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwwy <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, y, _, w ) = input;
	( w, w, w, y )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwwz <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, z, w ) = input;
	( w, w, w, z )
	
}

#[allow(dead_code)]
pub fn vec4_swizzle_wwww <T: Copy> ( input: ( T, T, T, T ) ) -> ( T, T, T, T )
{
	
	let ( _, _, _, w ) = input;
	( w, w, w, w )
	
}
