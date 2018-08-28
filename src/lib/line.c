/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 04:46:26 by astrole           #+#    #+#             */
/*   Updated: 2018/08/16 04:46:27 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_line	*create_line(t_vector2f *start, t_vector2f *end)
{
	t_line *line;

	line = ft_memalloc(sizeof(t_line));
	if (!line)
		return (NULL);
	if (start)
		line->start = *start;
	if (end)
		line->end = *end;
	return (line);
}

t_line	*set_line(t_line *line, t_vector2f *start,
				t_vector2f *end, t_color *color)
{
	if (line)
	{
		if (start)
			line->start = *start;
		if (end)
			line->end = *end;
		if (color)
		{
			line->color = *color;
			free(color);
		}
	}
	return (line);
}
