/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:50:54 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/24 04:28:35 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	parssing_1(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 2] != '1')
		{
			ft_printf("Error1\n");
			exit(0);
		}
		i++;
	}
	while (j < data->width - 1)
	{
		if (data->map[0][j] != '1' || data->map[data->height - 1][j] != '1')
		{
			ft_printf("Error2\n");
			exit(0);
		}
		j++;
	}
}

void	parssing_rectangular(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < (data->width - 1))
		{
			if (data->map[i][j] == '\0')
			{
				ft_printf("Error4\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	parssing_ecp(t_data *data)
{
	t_ecp	ecp;

	init(&ecp);
	while (ecp.i < data->height)
	{
		ecp.j = 0;
		while (ecp.j < data->width)
		{
			if (data->map[ecp.i][ecp.j] == 'E')
				ecp.e++;
			if (data->map[ecp.i][ecp.j] == 'C')
				ecp.c++;
			if (data->map[ecp.i][ecp.j] == 'P')
				ecp.p++;
			ecp.j++;
		}
		ecp.i++;
	}
	if (ecp.e != 1 || ecp.c < 1 || ecp.p != 1)
	{
		ft_printf("Error3\n");
		exit(0);
	}
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < height)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	parssing(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	parssing_1(data);
	parssing_ecp(data);
	parssing_rectangular(data);
	flood_fill(data, data->p_y, data->p_x);
	while (a < data->height)
	{
		b = 0;
		while (b < data->width - 1)
		{
			if (data->map[a][b] != '1' && data->map[a][b] != '0'
				&& data->map[a][b] != 'P' && data->map[a][b] != 'C')
			{
				ft_printf("Errorm\n");
				exit(0);
			}
			b++;
		}
		a++;
	}
	free_map(data->map, data->height);
	data->map = readmap(data->file, data);
}
