/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   money_flip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:43:38 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 18:24:31 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	money_flip(t_all *all)
{
    int i;
    int j;

    i = 0;
    
    while (all->data->map[i])
    {
        j = 0;
        
            while (all->data->map[i][j] != '\n')
            {
                if (all->data->map[i][j] == 'C')
                {
                    
                    mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
                        all->images->floor, j * 32, i * 32);
                    mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
                        all->images->money1, j * 32, i * 32);
                    mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
                        all->images->money2, j * 32, i * 32);
                    mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
                        all->images->money3, j * 32, i * 32);
                    mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
                        all->images->money4, j * 32, i * 32);
                    mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
                        all->images->money5, j * 32, i * 32);
                    mlx_put_image_to_window (all->data->mlx, all->data->mlx_win,
                        all->images->money6, j * 32, i * 32);
                }
                j++;
            }
        i++;
    }
    return (0);
}