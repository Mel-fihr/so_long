/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:21:38 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/28 08:25:41 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *line)
{
	if (!line)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

char	**allocate_map(int i)
{
	char	**map;

	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
	{
		ft_printf("Error\n");
		exit(0);
	}
	return (map);
}

void	fill_map(char **map, int fd, int height)
{
	int	i;

	i = 0;
	while (i < height)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
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
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->height = i;
	close(fd);
	map = allocate_map(i);
	fd = open(file, O_RDONLY);
	fill_map(map, fd, data->height);
	close(fd);
	return (map);
}
