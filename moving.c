/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:51:50 by cblasphe          #+#    #+#             */
/*   Updated: 2020/02/21 22:41:15 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_center(t_fdf *data)
{
	data->center_x = data->width / 2;
	data->center_y = data->height / 2;
	data->center_z = data->max_z / 2;
}

void	ft_move_to_center(t_point *point, t_fdf *data)
{
	point->x -= data->center_x;
	point->y -= data->center_y;
	point->z -= data->center_z;
}

void	ft_move_from_center(t_point *point, t_fdf *data)
{
	point->x += data->center_x;
	point->y += data->center_y;
	point->z += data->center_z;
}

void	ft_move(t_point *point1, t_point *point2, t_fdf *data)
{
	point2->x += data->shift_x;
	point2->y += data->shift_y;
	point1->x += data->shift_x;
	point1->y += data->shift_y;
}
