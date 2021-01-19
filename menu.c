/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:11:50 by cblasphe          #+#    #+#             */
/*   Updated: 2020/02/22 19:41:06 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_menu(t_fdf *data)
{
	char	*guide;

	guide = "up, down, right, left: ft_move";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0xffffe0, guide);
	guide = "numpad +, -: zoom everything";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xffffe0, guide);
	guide = "mainpad +, -: zoom z only";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0xffffe0, guide);
	guide = "num 7, 9, 4, 6, 8, 2 : rotation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0xffffe0, guide);
	guide = "I, O, P: change color scheme";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 65, 0xffffe0, guide);
	guide = "R: change projection";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0xffffe0, guide);
	guide = "ESC: exit";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 95, 0xffffe0, guide);
}
