/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 00:03:08 by astrole           #+#    #+#             */
/*   Updated: 2018/08/17 00:03:09 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static t_vector2f	parse_vector(char *value)
{
	int		x;
	int		y;
	char	**string;
	int		length;

	string = ft_strsplit(value, ',');
	x = 0;
	y = 0;
	length = 0;
	while (string[length])
		length++;
	if (length == 2)
	{
		x = ft_atoi(string[0]);
		y = ft_atoi(string[1]);
	}
	length = -1;
	while (string[++length])
		free(string[length]);
	free(string);
	return ((t_vector2f){x, y});
}

static t_color		parse_color(char *value)
{
	t_color color;
	char	**string;
	int		length;

	string = ft_strsplit(value, ',');
	color.a = 255;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	length = 0;
	while (string[length])
		length++;
	if (length >= 3)
	{
		color.r = ft_atoi(string[0]);
		color.g = ft_atoi(string[1]);
		color.b = ft_atoi(string[2]);
	}
	if (length == 4)
		color.a = ft_atoi(string[3]);
	length = -1;
	while (string[++length])
		free(string[length]);
	free(string);
	return ((t_color){color.r, color.g, color.b, color.a});
}

static void			get_value(t_config *config, char **values)
{
	if (ft_strcmp(values[0], "WIDTH") == 0)
		config->width = ft_atoi(values[1]);
	else if (ft_strcmp(values[0], "HEIGHT") == 0)
		config->height = ft_atoi(values[1]);
	else if (ft_strcmp(values[0], "SENSITIVITY") == 0)
		config->sensitivity = ft_atof(values[1]);
	else if (ft_strcmp(values[0], "RED") == 0)
		config->red = parse_vector(values[1]);
	else if (ft_strcmp(values[0], "GREEN") == 0)
		config->green = parse_vector(values[1]);
	else if (ft_strcmp(values[0], "BLUE") == 0)
		config->blue = parse_vector(values[1]);
	else if (ft_strcmp(values[0], "BACKGROUND") == 0)
		config->background = parse_color(values[1]);
	else
	{
		ft_putstr("Unrecognizable value ");
		ft_putendl(values[0]);
	}
}

static void			parse_line(t_config *config, char *line)
{
	char	**values;
	int		length;

	values = ft_strsplit(line, ' ');
	length = 0;
	while (values[length])
		length++;
	if (length == 2)
		get_value(config, values);
	length = -1;
	while (values[++length])
		free(values[length]);
	free(values);
}

t_config			*parse_config(char *name)
{
	t_config	*config;
	int			fd;
	int			ret;
	int			line_c;
	char		*line;

	config = ft_memalloc(sizeof(t_config));
	line_c = 0;
	if (!config)
		return (NULL);
	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != '#' && ft_strlen(line) > 1)
			parse_line(config, line);
		free(line);
		line_c++;
	}
	if (ret < 0)
	{
		free(config);
		return (NULL);
	}
	return (config);
}
