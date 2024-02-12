/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:19:21 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 12:50:39 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int    player_movement(int keycode, t_all *all)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < all->data->height)
    {
        j = 0;
        while (j < all->data->width)
        {
            if (all->data->map[i][j] == 'P')
            {
                if (keycode == 126)
                {
                    if (all->data->map[i - 1][j] == '0' || all->data->map[i - 1][j] == 'C' || all->data->map[i - 1][j] == 'E')
                    {
                        check_exit(all, i - 1, j);
                        up(all, i, j);
                        printf("move: %d\n", ++all->data->move);
                        return (0);
                    }
                }
                else if (keycode == 125)
                {
                    if (all->data->map[i + 1][j] == '0' || all->data->map[i + 1][j] == 'C' || all->data->map[i + 1][j] == 'E')
                    {
                        check_exit(all, i + 1, j);
                        down(all, i, j);
                        printf("move: %d\n", ++all->data->move);
                        return (0);
                    }
                }
                else if (keycode == 123)
                {
                    if (all->data->map[i][j - 1] == '0' || all->data->map[i][j - 1] == 'C' || all->data->map[i][j - 1] == 'E')
                    {
                        check_exit(all, i, j - 1);
                        left(all, i, j);
                        printf("move: %d\n", ++all->data->move);
                        return (0);
                    }
                }
                else if (keycode == 124)
                {
                    if (all->data->map[i][j + 1] == '0' || all->data->map[i][j + 1] == 'C' || all->data->map[i][j + 1] == 'E')
                    {
                        check_exit(all, i, j + 1);
                        right(all, i, j);
                        printf("move: %d\n", ++all->data->move);
                        return (0);
                    }
                }
                else if (keycode == 53)
                {
                    esc(all);
                    exit(0);
                }
            }
            j++;
        }
        i++;
    }
    return (0);
}

