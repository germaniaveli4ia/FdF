/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblasphe <cblasphe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:31:45 by cblasphe          #+#    #+#             */
/*   Updated: 2020/02/22 18:35:31 by cblasphe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*ft_init_fdf(void)
{
	t_fdf		*data;
	t_angle		*angle;

	data = ft_memalloc(sizeof(t_fdf));
	angle = ft_memalloc(sizeof(t_angle));
	data->angle = angle;
	data->angle->x = 0;
	data->angle->y = 0;
	data->angle->z = 0;
	data->iso = 1;
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 100;
	data->color1 = PINK;
	data->color2 = DARKBLUE;
	data->color3 = POWDERBLUE;
	data->color4 = SKYBLUE;
	data->color5 = AQUA;
	data->bits_per_pixel /= 8;
	data->zoom_z = 1;
	return (data);
}

void	ft_init_mlx(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data_addr = mlx_get_data_addr(data->img,
		&(data->bits_per_pixel), &(data->size_line), &(data->endian));
}

int		main(int argc, char **argv)
{
	t_fdf		*data;

	data = NULL;
	if (argc != 2 || !(ft_check_file(argv[1])))
		ft_error("Usage: ./fdf argument.fdf", data);
	data = ft_init_fdf();
	data->points = read_file(argv[1], data);
	if (!data->points)
		ft_error("Map is invalid", data);
	ft_init_mlx(data);
	ft_draw_all(data);
	mlx_hook(data->win_ptr, 2, 0, ft_bind_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
