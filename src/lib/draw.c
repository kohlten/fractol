/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 03:47:17 by astrole           #+#    #+#             */
/*   Updated: 2018/08/10 03:47:18 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

extern inline void	plot_point(t_window *window, t_image *image,
								t_vector2f pos, t_color color)
{
	if (image)
		image_draw_pixel(image, (t_vector2i){round(pos.x),
								round(pos.y)}, color);
	else
		mlx_pixel_put(window->mlx_ptr, window->win_ptr,
					pos.x, pos.y, color_to_dec(color));
}

void				fill(t_window *window, t_image *image, t_color color)
{
	t_vector2f pos;
	t_vector2i max;

	pos.x = -1;
	if (image)
		max = image->size;
	else
	{
		max.x = window->size.x;
		max.y = window->size.y;
	}
	while (++pos.x < max.x)
	{
		pos.y = -1;
		while (++pos.y < max.y)
			plot_point(window, image, pos, color);
	}
}
