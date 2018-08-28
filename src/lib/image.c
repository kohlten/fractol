/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 03:41:00 by astrole           #+#    #+#             */
/*   Updated: 2018/06/24 03:41:00 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	image_draw_pixel(t_image *image, t_vector2i pos, t_color color)
{
	int offset;

	if (pos.x < 0 || pos.x > image->size.x - 1 ||
		pos.y < 0 || pos.y > image->size.y - 1)
		return ;
	offset = (pos.x + pos.y * image->size.x) * image->bpp;
	*(int *)(image->ptr + offset) = color_to_dec(color);
}

void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, image->size.x * image->size.y * image->bpp);
}

t_image	*del_image(t_window *window, t_image *image)
{
	if (image)
	{
		if (image->image)
			mlx_destroy_image(window->mlx_ptr, image->image);
		ft_memdel((void **)&image);
	}
	return (NULL);
}

t_image	*new_image(t_window *window, t_vector2f size)
{
	t_image *image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(image->image = mlx_new_image(window->mlx_ptr, size.x, size.y)))
		return (del_image(window, image));
	image->ptr = mlx_get_data_addr(image->image, &image->bpp,
									&image->stride, &image->endian);
	image->bpp /= 8;
	image->size.x = size.x;
	image->size.y = size.y;
	return (image);
}

void	draw_image(t_window *window, t_image *image, t_vector2f *pos)
{
	if (pos)
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
							image->image, pos->x, pos->y);
	else
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
							image->image, 0, 0);
}
