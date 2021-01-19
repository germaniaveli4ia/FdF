/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:49:33 by cblasphe          #+#    #+#             */
/*   Updated: 2020/02/22 19:03:34 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_point *point1, t_point *point2, t_fdf *data)
{
	point2->x *= data->zoom;
	point2->y *= data->zoom;
	point2->z *= data->zoom;
	point1->x *= data->zoom;
	point1->y *= data->zoom;
	point1->z *= data->zoom;
}

void	ft_rotate(t_point *point, t_angle *angle)
{
	float	prev_x;
	float	prev_y;
	float	prev_z;

	prev_x = point->x;
	prev_y = point->y;
	prev_z = point->z;
	point->y = (prev_y) * cos(angle->x) + (prev_z) * sin(angle->x);
	point->z = -(prev_y) * sin(angle->x) + (prev_z) * cos(angle->x);
	prev_y = point->y;
	prev_z = point->z;
	point->x = (prev_x) * cos(angle->y) + (prev_z) * sin(angle->y);
	point->z = -(prev_x) * sin(angle->y) + (prev_z) * cos(angle->y);
	prev_x = point->x;
	prev_z = point->z;
	point->x = (prev_x) * cos(angle->z) - (prev_y) * sin(angle->z);
	point->y = (prev_x) * sin(angle->z) + (prev_y) * cos(angle->z);
}

void	iso(float *x, float *y, float *z)
{
	float previous_x;
	float previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -*z + (previous_x + previous_y) * sin(0.523599);
}

void	ft_transform(t_point *strt, t_point *end, t_fdf *data)
{
	ft_update_center(data);
	ft_move_to_center(strt, data);
	ft_move_to_center(end, data);
	strt->z *= data->zoom_z;
	end->z *= data->zoom_z;
	ft_rotate(strt, data->angle);
	ft_rotate(end, data->angle);
	if (data->iso)
	{
		iso(&(strt->x), &(strt->y), &(strt->z));
		iso(&(end->x), &(end->y), &(end->z));
	}
	ft_move_from_center(strt, data);
	ft_move_from_center(end, data);
	ft_zoom(strt, end, data);
	ft_move(strt, end, data);
}
