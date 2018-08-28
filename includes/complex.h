#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

double 			norm_sqr(t_complex c);
t_complex		mul_complex(t_complex x, t_complex y);
t_complex		add_complex(t_complex x, t_complex y);
t_complex		t_complex_constuctor(double re, double im);

#endif