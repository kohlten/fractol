/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 03:41:00 by astrole           #+#    #+#             */
/*   Updated: 2018/06/24 03:41:00 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	plot_line_low(t_window *window,
						t_image *image, t_line *line)
{
	line->reg.yi = 1;
	line->reg.d.x = line->end.x - line->start.x;
	line->reg.d.y = line->end.y - line->start.y;
	if (line->reg.d.y < 0)
	{
		line->reg.yi = -1;
		line->reg.d.y = -line->reg.d.y;
	}
	line->reg.d2 = 2 * line->reg.d.y - line->reg.d.x;
	line->reg.pos = (t_vector2f) {line->start.x, line->start.y};
	while (line->reg.pos.x < line->end.x)
	{
		plot_point(window, image, line->reg.pos, line->color);
		if (line->reg.d2 > 0)
		{
			line->reg.pos.y += line->reg.yi;
			line->reg.d2 -= 2 * line->reg.d.x;
		}
		line->reg.d2 += 2 * line->reg.d.y;
		line->reg.pos.x++;
	}
}

static void	plot_line_high(t_window *window,
						t_image *image, t_line *line)
{
	line->reg.xi = 1;
	line->reg.d.x = line->end.x - line->start.x;
	line->reg.d.y = line->end.y - line->start.y;
	if (line->reg.d.x < 0)
	{
		line->reg.xi = -1;
		line->reg.d.x = -line->reg.d.x;
	}
	line->reg.d2 = 2 * line->reg.d.x - line->reg.d.y;
	line->reg.pos = (t_vector2f) {line->start.x, line->start.y};
	while (line->reg.pos.y < line->end.y)
	{
		plot_point(window, image, line->reg.pos, line->color);
		if (line->reg.d2 > 0)
		{
			line->reg.pos.x += line->reg.xi;
			line->reg.d2 -= 2 * line->reg.d.y;
		}
		line->reg.d2 += 2 * line->reg.d.x;
		line->reg.pos.y++;
	}
}

void		drawline(t_window *window, t_image *image, t_line *line)
{
	t_vector2f start;
	t_vector2f end;

	start = line->start;
	end = line->end;
	if (fabs(end.y - start.y) < fabs(end.x - start.x))
	{
		if (start.x > end.x)
			plot_line_low(window, image,
				set_line(line, &end, &start, 0));
		else
			plot_line_low(window, image, line);
	}
	else
	{
		if (start.y > end.y)
			plot_line_high(window, image,
				set_line(line, &end, &start, 0));
		else
			plot_line_high(window, image, line);
	}
}
