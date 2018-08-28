/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 03:48:11 by astrole           #+#    #+#             */
/*   Updated: 2018/08/10 03:48:12 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	terminate(char *reason, int ret)
{
	ft_putstr(reason);
	exit(ret);
}

void	clean(t_window *window, t_image *image, t_config *config)
{
	del_image(window, image);
	if (config)
		free(config);
}
