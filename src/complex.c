#include "fractol.h"

double norm_sqr(t_complex c)
{
	return ((c.re * c.re) + (c.im * c.im))
}

extern inline t_complex mul_complex(t_complex x, t_complex y)
{
	double re;
	double im;

	re = (x.re * y.re) - (x.im * y.im);
	im = (x.re * y.im) + (x.im * y.re);
	return (t_complex_constuctor(re, im)); 
}

extern inline t_complex add_complex(t_complex x, t_complex y)
{
	return (t_complex_constuctor(x.re + y.re, x.im + y.im));
}

t_complex t_complex_constuctor(double re, double im)
{
	return (t_complex){re, im};
}
