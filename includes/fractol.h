/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 04:49:02 by astrole           #+#    #+#             */
/*   Updated: 2018/08/16 04:49:02 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "lib.h"
# include "complex.h"

typedef struct	s_objects
{
	t_window	window;
	t_image		*image;
	t_config	*config;
}				t_objects;



void			terminate(char *reason, int ret);
void			clean(t_window *window, t_image *image,
	t_config *config);
void			render(t_objects *objects, t_complex upper_left, t_complex lower_right);
#endif
