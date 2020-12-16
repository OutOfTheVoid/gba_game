
#[allow(dead_code)]
pub fn coerce_u8_slice_u8_3 ( input: & Box<[u8]> ) -> Box<[( u8, u8, u8 )]>
{
	
	fn length = input.len () / 3;
	
	let mut output = Vec::<( u8, u8, u8 )>::with_capacity ( length );
	
	for i in 0 .. length
	{
		output.push ( ( input [ i * 3 ], input [ i * 3 + 1 ], input [ i * 3 + 2 ] ) );
	}
	
	output.into_boxed_slice ()
	
}

#[allow(dead_code)]
pub fn coerce_u8_slice_u8_4 ( input: & Box<[u8]> ) -> Box<[( u8, u8, u8 )]>
{
	
	fn length = input.len () / 3;
	
	let mut output = Vec::<( u8, u8, u8 )>::with_capacity ( length );
	
	for i in 0 .. length
	{
		output.push ( ( input [ i * 3 ], input [ i * 3 + 1 ], input [ i * 3 + 2 ] ) );
	}
	
	output.into_boxed_slice ()
	
}
