/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 03:58:38 by astrole           #+#    #+#             */
/*   Updated: 2018/08/10 03:58:39 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_up_values(t_config *config, t_window *window)
{
	if (config)
	{
		window->size.x = config->width;
		window->size.y = config->height;
	}
	else
	{
		window->size.x = 1000;
		window->size.y = 1000;
	}
}

static void		start(t_objects *objects)
{
	//if (objects->config)
	//	fill(&objects->window, objects->image, objects->config->background);
	draw_image(&objects->window, objects->image, 0);
	mlx_key_hook(objects->window.win_ptr, hook_keydown, objects);
	mlx_hook(objects->window.win_ptr, 17, 0, quit_application, objects);
	mlx_loop(objects->window.mlx_ptr);
}

int				main(int argc, char **argv)
{
	t_objects objects;

	(void)argc;
	(void)argv;

	objects.config = parse_config("config.txt");
	if (!objects.config)
		ft_putendl("Failed to read config, falling back to normal values!");
	set_up_values(objects.config, &objects.window);
	if (!(objects.window.mlx_ptr = mlx_init()))
		terminate("Failed to connect to mlx", -1);
	if (!(objects.window.win_ptr = mlx_new_window(objects.window.mlx_ptr,
		objects.window.size.x, objects.window.size.y, "Fractol")))
		terminate("Failed to create a window!", -2);
	objects.image = new_image(&objects.window,
		(t_vector2f){objects.window.size.x, objects.window.size.y});
	render(&objects, t_complex_constuctor(-2.5, 1.0), t_complex_constuctor(1.0, -1.0));
	start(&objects);
	return (0);
}
