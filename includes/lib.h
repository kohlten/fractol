/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 03:21:23 by astrole           #+#    #+#             */
/*   Updated: 2018/08/17 03:21:25 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include <mlx.h>

/*
** VECTORS
*/
typedef struct		s_dvector3f
{
	double			x;
	double			y;
	double			z;
}					t_vector3f;

typedef struct		s_vector2f
{
	double			x;
	double			y;
}					t_vector2f;

typedef struct		s_vector2i
{
	long long		x;
	long long		y;
}					t_vector2i;

/*
** COLOR
*/

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

/*
** LINES
*/

typedef struct		s_reg
{
	t_vector2f		d;
	t_vector2f		pos;
	double			d2;
	int				xi;
	int				yi;
}					t_reg;

typedef struct		s_line
{
	t_vector2f		start;
	t_vector2f		end;
	t_color			color;
	t_reg			reg;
}					t_line;

/*
** CONFIG
*/

typedef struct		s_config
{
	size_t			width;
	size_t			height;
	double			sensitivity;
	t_vector2f		red;
	t_vector2f		green;
	t_vector2f		blue;
	t_color			background;
}					t_config;

/*
** IMAGE
*/

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	t_vector2i		size;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

/*
** WINDOW
*/

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_vector2f		size;

}					t_window;

/*
** IMAGE
*/
void				image_draw_pixel(t_image *image,
	t_vector2i pos, t_color color);
void				clear_image(t_image *image);
t_image				*del_image(t_window *window, t_image *image);
t_image				*new_image(t_window *window, t_vector2f size);
void				draw_image(t_window *window,
	t_image *image, t_vector2f *pos);

/*
** KEYBOARD
*/
int					hook_keydown(int key, t_window *window);
int					quit_application(t_window *window);

/*
** MATH
*/
double				map(double n, t_vector2f range1, t_vector2f range2);
double				map_constrain(double n, t_vector2f range1,
	t_vector2f range2);
double				constrain(double n, double low, double high);
void				swap(double *x, double *y);
t_vector2f			*convert_3d_2d(t_vector3f *vec3,
	t_vector2f *vec2, double zscale);

/*
** CONFIG
*/
t_config			*parse_config(char *name);
t_color				*get_color(t_config *config, double height);

/*
** DRAW
*/
void				plot_point(t_window *window, t_image *image,
								t_vector2f pos, t_color color);
void				drawline(t_window *window, t_image *image, t_line *line);
t_line				*create_line(t_vector2f *start, t_vector2f *end);
t_line				*set_line(t_line *line,
	t_vector2f *start, t_vector2f *end, t_color *color);
void				fill(t_window *window, t_image *image, t_color color);

/*
** COLOR
*/
unsigned int		color_to_dec(t_color color);
t_color				*reset_color(t_color *color);
t_color				t_color_constructor(unsigned char r, unsigned char g,
	unsigned char b, unsigned char a);

#endif
