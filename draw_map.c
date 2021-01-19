/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:33:52 by wmarya            #+#    #+#             */
/*   Updated: 2020/02/21 22:33:55 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *data, int x, int y, int color)
{
	int		i;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = x * data->bits_per_pixel / 8 + y * data->size_line;
	data->data_addr[i] = color;
	data->data_addr[++i] = color >> 8;
	data->data_addr[++i] = color >> 16;
}

void	ft_clear_image(t_fdf *data)
{
	ft_bzero(data->data_addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
}

void	ft_draw_line(t_point strt, t_point end, t_fdf *data)
{
	float		x_step;
	float		y_step;
	int			max;
	t_point		p1;
	t_point		p2;

	ft_transform(&strt, &end, data);
	x_step = end.x - strt.x;
	y_step = end.y - strt.y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	p1 = strt;
	p2 = end;
	while ((int)(strt.x - end.x) || (int)(strt.y - end.y))
	{
		put_pixel(data, strt.x, strt.y, ft_get_color(p1, p2, strt));
		strt.x += x_step;
		strt.y += y_step;
	}
}

void	ft_draw_map(t_fdf *data)
{
	int		x;
	int		y;
	t_point	**points;

	points = data->points;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_draw_line(points[y][x], points[y][x + 1], data);
			if (y < data->height - 1)
				ft_draw_line(points[y][x], points[y + 1][x], data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	ft_draw_menu(data);
}

void	ft_draw_all(t_fdf *data)
{
	ft_set_basic_colors(data, data->points);
	ft_draw_map(data);
	ft_draw_menu(data);
}
