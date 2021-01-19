/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:42:49 by wmarya            #+#    #+#             */
/*   Updated: 2020/02/22 19:12:25 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_mod(float a)
{
	return (a < 0 ? a * -1 : a);
}

float	ft_max(float a, float b)
{
	return (a > b ? a : b);
}

void	ft_error(char *s, t_fdf *data)
{
	if (data)
		ft_clear_fdf(data);
	if (s && *s)
		ft_putendl(s);
	exit(1);
}

int		ft_check_file(char *file)
{
	int		fd;
	int		ret;
	char	buf[2];

	fd = open(file, O_RDONLY);
	if (fd < 0 || (ret = read(fd, buf, 1)) <= 0)
		return (0);
	close(fd);
	return (1);
}
