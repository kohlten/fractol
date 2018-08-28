#include "fractol.h"

static int escape_time(t_complex c, unsigned int limit)
{
	t_complex z;
	unsigned int i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (i < limit)
	{
		z = mul_complex(z, z);
		z = add_complex(z, c);
		if (norm_sqr(z) > 50.0)
			return (i);
		i++;
	}
	return (-1);
}

static t_complex pixel_to_point(t_vector2f size, t_vector2f point, t_complex upper_left, t_complex lower_right)
{
	double width;
	double height;

	width = lower_right.re - upper_left.re;
	height = upper_left.im - lower_right.im;

	return t_complex_constuctor(upper_left.re + point.x * width / size.x,
								upper_left.im - point.y * height / size.y);
}

void render(t_objects *objects, t_complex upper_left, t_complex lower_right)
{
	int i;
	int j;
	t_complex point;
	int	diff;
	//int x;
	//int y;
	//double zoom = 1000;

	i = 0;
	while (i < objects->window.size.x)
	{
		j = 0;
		while (j < objects->window.size.y)
		{
			point = pixel_to_point(objects->window.size, (t_vector2f){i, j}, upper_left, lower_right);
			diff = escape_time(point, 5000);
			//x = (objects->window.size.x / 2) + (i / objects->window.size.x - 0.5) * zoom;
			//y = (objects->window.size.y / 2) + (j / objects->window.size.y - 0.5) * zoom;
			if (diff > -1)
				plot_point(&objects->window, objects->image, (t_vector2f){i, j},
					t_color_constructor(255 - diff, 255 - diff, 255 - diff, 255));

			else
				plot_point(&objects->window, objects->image, (t_vector2f){i, j},
					t_color_constructor(0, 0, 0, 255));
			j++;
		}
		i++;
	}
}