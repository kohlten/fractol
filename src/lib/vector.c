/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 03:48:23 by astrole           #+#    #+#             */
/*   Updated: 2018/08/10 03:48:24 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_vector2f	*convert_3d_2d(t_vector3f *vec3, t_vector2f *vec2, double zscale)
{
	double tmp;
	double rad;

	rad = -60.0 * M_PI / 180.0;
	vec2->x = (vec3->x + (vec3->z * zscale)) / sqrt(2.0);
	vec2->y = (vec3->x + 2.0 * vec3->y - (vec3->z * zscale)) / sqrt(6.0);
	tmp = vec2->x;
	vec2->x = vec2->x * cos(rad) - vec2->y * sin(rad);
	vec2->y = vec2->y * cos(rad) + tmp * sin(rad);
	return (vec2);
}
