/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:26:45 by wmarya            #+#    #+#             */
/*   Updated: 2020/02/22 19:26:49 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_fdf(t_fdf *data)
{
	size_t	len;

	len = 0;
	if (data->points)
	{
		while (data->points[len])
			len++;
		while (len--)
			free(data->points[len]);
	}
	free(data->points);
	data->points = NULL;
	free(data);
	data = NULL;
}
