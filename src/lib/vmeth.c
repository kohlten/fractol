/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmeth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 03:48:37 by astrole           #+#    #+#             */
/*   Updated: 2018/08/10 03:48:38 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

double	constrain(double n, double low, double high)
{
	return (fmax(fmin(n, high), low));
}

double	map(double n, t_vector2f range1, t_vector2f range2)
{
	double newval;

	newval = (n - range1.x) /
	(range1.y - range1.x) * (range2.y - range2.x) + range2.x;
	return (newval);
}

double	map_constrain(double n, t_vector2f range1, t_vector2f range2)
{
	double newval;

	newval = (n - range1.x) /
	(range1.y - range1.x) * (range2.y - range2.x) + range2.x;
	if (range2.x < range2.y)
		return (constrain(newval, range2.x, range2.y));
	else
		return (constrain(newval, range2.y, range2.x));
}

void	swap(double *x, double *y)
{
	double tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
