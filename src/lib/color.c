/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 03:41:00 by astrole           #+#    #+#             */
/*   Updated: 2018/06/24 03:41:00 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

unsigned int	color_to_dec(t_color color)
{
	unsigned int	val;
	unsigned char	alpha;

	alpha = map(color.a, (t_vector2f){0, 255}, (t_vector2f){255, 0});
	val = (alpha << 24) | (color.r << 16) | (color.g << 8) | color.b;
	return (val);
}

t_color			*reset_color(t_color *color)
{
	color->r = 255;
	color->g = 255;
	color->b = 255;
	color->a = 255;
	return (color);
}

t_color			*get_color(t_config *config, double height)
{
	t_color		*color;
	t_vector2f	max;

	color = ft_memalloc(sizeof(color));
	color->a = 255;
	if (config)
	{
		max = config->red;
		if (config->red.x != -1)
			color->r = map(height, (t_vector2f){0, 20}, max);
		max = config->green;
		if (config->green.x != -1)
			color->g = map(height, (t_vector2f){0, 20}, max);
		max = config->blue;
		if (config->blue.x != -1)
			color->b = map(height, (t_vector2f){0, 20}, max);
		if (config->red.x != -1 || config->green.x != -1
			|| config->blue.x != -1)
			return (color);
	}
	return (reset_color(color));
}

t_color		t_color_constructor(unsigned char r, unsigned char g,
	unsigned char b, unsigned char a)
{
	return ((t_color){r, g, b, a});
}
