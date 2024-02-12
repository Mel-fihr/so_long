/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:21:48 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/06 18:05:09 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	left(t_all *all, int i, int j)
{
	if (all->data->map[i][j - 1] == '0' || all->data->map[i][j - 1] == 'C')
	{
		if (all->data->map[i][j - 1] == 'C')
			all->data->collect--;
		all->data->map[i][j] = '0';
		all->data->map[i][j - 1] = 'P';
		mlx_put_image_to_window (all->data->mlx,
			all->data->mlx_win, all->images->floor, j * 32, i * 32);
		mlx_put_image_to_window (all->data->mlx,
			all->data->mlx_win, all->images->floor, (j - 1) * 32, i * 32);
		mlx_put_image_to_window (all->data->mlx,
			all->data->mlx_win, all->images->player, (j - 1) * 32, i * 32);
	}
}
