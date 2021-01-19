/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:53:27 by cblasphe          #+#    #+#             */
/*   Updated: 2020/02/22 19:22:23 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_angle_key(int key, t_fdf *data)
{
	if (key == 15)
	{
		data->angle->x = 0;
		data->angle->y = 0;
		data->angle->z = 0;
		data->iso = data->iso ? 0 : 1;
	}
	if ((key == 91) || (key == 1))
		data->angle->x -= 0.2;
	else if ((key == 84) || (key == 13))
		data->angle->x += 0.2;
	else if ((key == 86) || (key == 0))
		data->angle->y -= 0.2;
	else if ((key == 88) || (key == 2))
		data->angle->y += 0.2;
	else if ((key == 89) || (key == 12))
		data->angle->z -= 0.2;
	else if ((key == 92) || (key == 14))
		data->angle->z += 0.2;
}

void	ft_shift_key(int key, t_fdf *data)
{
	int step;

	step = data->zoom ? data->zoom : 1;
	if (key == 126)
		data->shift_y -= step;
	else if (key == 125)
		data->shift_y += step;
	else if (key == 123)
		data->shift_x -= step;
	else if (key == 124)
		data->shift_x += step;
}

void	ft_color_key(int key, t_fdf *data)
{
	if (key == 31)
	{
		data->color1 = LIGHTGREEN;
		data->color2 = INDIGO;
		data->color3 = BLUEVIOLET;
		data->color4 = VIOLET;
		data->color5 = AQUA;
	}
	else if (key == 35)
	{
		data->color1 = PINK;
		data->color2 = DARKBLUE;
		data->color3 = POWDERBLUE;
		data->color4 = SKYBLUE;
		data->color5 = VIOLET;
	}
	else if (key == 34)
	{
		data->color1 = CYAN;
		data->color2 = PLUM;
		data->color3 = GOLD;
		data->color4 = AQUA;
		data->color5 = PINK;
	}
}

void	ft_zoom_key(int key, t_fdf *data)
{
	if (key == 69)
		data->zoom += 1;
	else if (key == 78 && data->zoom > 1)
		data->zoom -= 1;
	else if (key == 24)
		data->zoom_z += 0.1;
	else if (key == 27)
		data->zoom_z -= 0.1;
}

int		ft_bind_key(int key, t_fdf *data)
{
	if (key == 53)
	{
		ft_error("", data);
	}
	ft_shift_key(key, data);
	ft_zoom_key(key, data);
	ft_angle_key(key, data);
	ft_color_key(key, data);
	ft_clear_image(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw_all(data);
	return (0);
}
