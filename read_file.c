/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:45:38 by cblasphe          #+#    #+#             */
/*   Updated: 2020/02/22 19:38:44 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_update_width_and_height(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		current_width;

	data->width = 0;
	data->height = 0;
	current_width = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		current_width = ft_count_words(line, ' ');
		if (!data->height)
			data->width = current_width;
		if (data->height && data->width != current_width)
			return (0);
		data->height++;
		free(line);
	}
	close(fd);
	return (data->width && data->height);
}

t_point	*get_z_line(char *line, int width, int y)
{
	char	**nb;
	int		i;
	t_point	*z_line;

	i = 0;
	if (!width)
		return (NULL);
	if (!(z_line = (t_point*)malloc(sizeof(t_point) * (width + 1))))
		return (NULL);
	nb = ft_strsplit(line, ' ');
	if (!nb)
	{
		free(z_line);
		return (NULL);
	}
	while (nb[i])
	{
		z_line[i].z = (float)ft_atoi(nb[i]);
		z_line[i].x = i;
		z_line[i].y = y;
		free(nb[i]);
		i++;
	}
	free(nb);
	return (z_line);
}

void	ft_update_camera(t_fdf *data)
{
	while (data->zoom * data->width > WIDTH / 2
		|| data->zoom * data->height > HEIGHT / 2)
		data->zoom--;
	data->shift_x = WIDTH / 2 - data->width * data->zoom / 2;
	data->shift_y = HEIGHT / 2 - data->height * data->zoom / 2;
}

t_point	**read_file(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;
	t_point	**points;

	points = NULL;
	if (!(ft_update_width_and_height(filename, data)))
		return (NULL);
	ft_update_camera(data);
	if (!(points = (t_point **)malloc(sizeof(t_point*) * (data->height + 1))))
		return (NULL);
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		points[i] = get_z_line(line, ft_count_words(line, ' '), i);
		free(line);
		i++;
	}
	close(fd);
	points[i] = NULL;
	ft_find_max_height(data, points);
	return (points);
}
