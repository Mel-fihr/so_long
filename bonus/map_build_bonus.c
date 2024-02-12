/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:40:06 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 18:00:51 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xpm_to_img(t_images *images, t_data *data)
{
	int	width;
	int	height;

	data->move = 0;
	images->wall = mlx_xpm_file_to_image(data->mlx, "./images/wall.xpm",
			&width, &height);
	images->floor = mlx_xpm_file_to_image(data->mlx, "./images/floor.xpm",
			&width, &height);
	images->exite = mlx_xpm_file_to_image(data->mlx, "./images/exit.xpm",
			&width, &height);
	images->collect = mlx_xpm_file_to_image(data->mlx, "./images/collect.xpm",
			&width, &height);
	images->player = mlx_xpm_file_to_image(data->mlx, "./images/player.xpm",
			&width, &height);
	images->money1 = mlx_xpm_file_to_image(data->mlx, "./images/1.xpm",
			&width, &height);
	images->money2 = mlx_xpm_file_to_image(data->mlx, "./images/2.xpm",
			&width, &height);
	images->money3 = mlx_xpm_file_to_image(data->mlx, "./images/3.xpm",
			&width, &height);
	images->money4 = mlx_xpm_file_to_image(data->mlx, "./images/4.xpm",
			&width, &height);
	images->money5 = mlx_xpm_file_to_image(data->mlx, "./images/5.xpm",
			&width, &height);
	images->money6 = mlx_xpm_file_to_image(data->mlx, "./images/6.xpm",
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

void	move_xpm_to_img(t_images *images, t_data *data)
{
	int	width;
	int	height;

	images->left = mlx_xpm_file_to_image(data->mlx, "./images/image.xpm",
			&width, &height);
}

void	put_map(t_data *data, t_images *images)
{
	int	i;
	int	j;

	i = 0;
	data->collect = 0;
	xpm_to_img(images, data);
	move_xpm_to_img(images, data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			put_image(data, images, i, j);
			printf("%c", data->map[i][j]);
			fflush(stdout);
			j++;
		}
		printf("\n");
		fflush(stdout);
		i++;
	}
	puts("Map is ready");
}
