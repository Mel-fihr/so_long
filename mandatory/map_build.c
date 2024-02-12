/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:40:06 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 00:11:41 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_images *images, t_data *data)
{
	int	width;
	int	height;

	data->move = 0;
	images->wall = mlx_xpm_file_to_image(data->mlx, "./mandatory/images/wall.xpm",
			&width, &height);
	images->floor = mlx_xpm_file_to_image(data->mlx, "./mandatory/images/floor.xpm",
			&width, &height);
	images->exite = mlx_xpm_file_to_image(data->mlx, "./mandatory/images/exit.xpm",
			&width, &height);
	images->collect = mlx_xpm_file_to_image(data->mlx, "./mandatory/images/collect.xpm",
			&width, &height);
	images->player = mlx_xpm_file_to_image(data->mlx, "./mandatory/images/player.xpm",
			&width, &height);
}

void	put_image(t_data *data, t_images *images, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->wall,
			j * 32, i * 32);
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->floor,
			j * 32, i * 32);
	if (data->map[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->floor,
			j * 32, i * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->player,
			j * 32, i * 32);
	}
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->exite,
			j * 32, i * 32);
	if (data->map[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->floor,
			j * 32, i * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->collect,
			j * 32, i * 32);
		data->collect++;
	}
}

void	put_map(t_data *data, t_images *images)
{
	int	i;
	int	j;

	i = 0;
	data->collect = 0;
	xpm_to_img(images, data);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			put_image(data, images, i, j);
			j++;
		}
		i++;
	}
}
