/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:31:54 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/28 08:23:23 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	p_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_x = j;
				data->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_images	images;
	t_all		all;

	if (ac != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	data.file = av[1];
	check_file_extention(av[1]);
	data.map = readmap(av[1], &data);
	p_x_y(&data);
	parssing(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,
			(data.width - 1) * 32, data.height * 32, "so_long");
	put_map(&data, &images);
	all.data = &data;
	all.images = &images;
	mlx_hook(data.mlx_win, 2, 1L << 0, player_movement, &all);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_game, &all);
	mlx_loop(data.mlx);
	return (0);
}
