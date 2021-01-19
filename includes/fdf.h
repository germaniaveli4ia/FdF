/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:57:30 by cblasphe          #+#    #+#             */
/*   Updated: 2020/02/22 19:08:58 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include "colors.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef struct	s_angle
{
	float		x;
	float		y;
	float		z;
}				t_angle;
typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	float		max_z;
	float		min_z;
	int			zoom;
	float		zoom_z;
	int			iso;
	int			color;
	int			color1;
	int			color2;
	int			color3;
	int			color4;
	int			color5;
	float		center_x;
	float		center_y;
	float		center_z;
	int			shift_x;
	int			shift_y;
	t_angle		*angle;
	t_point		**points;
}				t_fdf;

t_point			**read_file(char *filename, t_fdf *data);
void			ft_clear_image(t_fdf *data);
void			ft_draw_line(t_point strt, t_point end, t_fdf *data);
void			ft_draw_map(t_fdf *data);
void			ft_update_center(t_fdf *data);
void			ft_move(t_point *point1, t_point *point2, t_fdf *data);
void			ft_move_to_center(t_point *point, t_fdf *data);
void			ft_move_from_center(t_point *point, t_fdf *data);
void			ft_rotate(t_point *point, t_angle *angle);
void			ft_zoom(t_point *point1, t_point *point2, t_fdf *data);
void			ft_clear_fdf(t_fdf *data);
int				ft_find_max_height(t_fdf *data, t_point **point_matrix);
void			ft_error(char *s, t_fdf *data);
int				ft_bind_key(int key, t_fdf *data);
void			ft_draw_menu(t_fdf *data);
void			ft_draw_all(t_fdf *data);
int				ft_get_color(t_point strt, t_point end, t_point cur);
void			ft_set_basic_colors(t_fdf *data, t_point **point_matrix);
int				ft_validate(char *line);
void			ft_transform(t_point *strt, t_point *end, t_fdf *data);
float			ft_mod(float a);
float			ft_max(float a, float b);
int				ft_check_file(char *file);

#endif
