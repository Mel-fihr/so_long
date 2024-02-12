/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:31:54 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 18:18:05 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <mlx.h>

void	check_fd(int fd)
{
	if (fd < 0)
	{
		printf("Error\n");
		exit(0);
	}
}

void	check_line(char *line)
{
	if (!line)
	{
		printf("Error\n");
		exit(0);
	}
}

char	**readmap(char *file, t_data *data)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	check_line(line);
	data->width = ft_strlen(line);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	data->height = i;
	close(fd);
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (i < data->height)
		map[i++] = get_next_line(fd);
	return (map[i] = NULL, close(fd), map);
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
		printf("Error\n");
		return (0);
	}
	data.file = av[1];
	data.map = readmap(av[1], &data);
	p_x_y(&data);
	parssing(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,
			(data.width - 1) * 32, data.height * 32, "so_long");
	put_map(&data, &images);
	puts("Welcome to so_long");
	all.data = &data;
	all.images = &images;
	mlx_hook(data.mlx_win, 2, 1L << 0, player_movement, &all);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_game, &all);
	mlx_loop_hook(data.mlx, &money_flip, &all);
	mlx_loop(data.mlx);
	return (0);
}
