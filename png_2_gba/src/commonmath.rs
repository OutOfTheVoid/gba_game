use std;

pub trait Sqrt
{
	
	fn sqrt ( self ) -> Self;
	
}

impl Sqrt for f32 { fn sqrt ( self ) -> Self { f32::sqrt ( self ) } }
impl Sqrt for f64 { fn sqrt ( self ) -> Self { f64::sqrt ( self ) } }

pub trait One // Multiplicative identity
{
	
	fn get_one () -> Self;
	
}

pub trait Zero // additive identity
{
	
	fn get_zero () -> Self;
	
}

pub trait HasPi 
{
	
	fn get_pi () -> Self;
	fn get_pi_over_2 () -> Self;
	
}

pub trait BasicTrig: HasPi
{
	
	fn tan ( x: Self ) -> Self;
	fn cos ( x: Self ) -> Self;
	fn sin ( x: Self ) -> Self;
	
}

impl One for f32 { fn get_one () -> f32 { 1.0 } }
impl One for f64 { fn get_one () -> f64 { 1.0 } }

impl HasPi for f32
{
	fn get_pi () -> f32 { std::f32::consts::PI }
	fn get_pi_over_2 () -> f32 { std::f32::consts::FRAC_PI_2 }
}

impl BasicTrig for f32
{
	
	fn tan ( x: f32 ) -> f32 { x.tan () }
	fn cos ( x: f32 ) -> f32 { x.cos () }
	fn sin ( x: f32 ) -> f32 { x.sin () }
	
}

impl HasPi for f64
{
	fn get_pi () -> f64 { std::f64::consts::PI }
	fn get_pi_over_2 () -> f64 { std::f64::consts::FRAC_PI_2 }
}

impl BasicTrig for f64
{
	
	fn tan ( x: f64 ) -> f64 { x.tan () }
	fn cos ( x: f64 ) -> f64 { x.cos () }
	fn sin ( x: f64 ) -> f64 { x.sin () }
	
}

impl Zero for f32 { fn get_zero () -> f32 { 0.0 } }
impl Zero for f64 { fn get_zero () -> f64 { 0.0 } }
