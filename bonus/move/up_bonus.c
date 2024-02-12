/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:17:08 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 00:22:48 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	up(t_all *all, int i, int j)
{
	if (all->data->map[i - 1][j] == '0' || all->data->map[i - 1][j] == 'C')
	{
		if (all->data->map[i - 1][j] == 'C')
			all->data->collect--;
		all->data->map[i][j] = '0';
		all->data->map[i - 1][j] = 'P';
		mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
			all->images->floor, j * 32, i * 32);
		mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
			all->images->floor, j * 32, (i - 1) * 32);
		mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
			all->images->player, j * 32, (i - 1) * 32);
	}
}
