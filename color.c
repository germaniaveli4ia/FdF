/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:53:33 by wmarya            #+#    #+#             */
/*   Updated: 2020/02/21 20:01:30 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_find_max_height(t_fdf *data, t_point **point_matrix)
{
	float	max_z;
	float	min_z;
	int		x;
	int		y;

	max_z = point_matrix[0][0].z;
	min_z = max_z;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (point_matrix[y][x].z > max_z)
				max_z = point_matrix[y][x].z;
			if (point_matrix[y][x].z < min_z)
				min_z = point_matrix[y][x].z;
			x++;
		}
		y++;
	}
	data->min_z = min_z;
	data->max_z = max_z;
	return (max_z);
}

int		get_rgb(int strt, int end, float saturation)
{
	return ((int)((1 - saturation) * strt + saturation * end));
}

float	get_saturation(int strt, int end, int cur)
{
	float	cur_position;
	float	total_length;

	total_length = end - strt;
	cur_position = cur - strt;
	return (total_length == 0 ? 1.0 : cur_position / total_length);
}

void	ft_set_basic_colors(t_fdf *data, t_point **point_matrix)
{
	int		x;
	int		y;
	float	s;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			s = get_saturation(data->min_z, data->max_z, point_matrix[y][x].z);
			if (s < 0.2)
				point_matrix[y][x].color = data->color1;
			else if (s < 0.4)
				point_matrix[y][x].color = data->color2;
			else if (s < 0.6)
				point_matrix[y][x].color = data->color3;
			else if (s < 0.8)
				point_matrix[y][x].color = data->color4;
			else
				point_matrix[y][x].color = data->color5;
			x++;
		}
		y++;
	}
}

int		ft_get_color(t_point strt, t_point end, t_point cur)
{
	float	saturation;
	int		red;
	int		green;
	int		blue;

	if (cur.color == end.color)
		return (cur.color);
	if (ft_mod(end.x - strt.x) > ft_mod(end.y - strt.y))
		saturation = get_saturation(strt.x, end.x, cur.x);
	else
		saturation = get_saturation(strt.y, end.y, cur.y);
	red = get_rgb((strt.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
	saturation);
	green = get_rgb((strt.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
	saturation);
	blue = get_rgb(strt.color & 0xFF, end.color & 0xFF, saturation);
	return ((red << 16) | (green << 8) | blue);
}
