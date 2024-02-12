/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:17:39 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 00:22:34 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    flood_fill(t_data *data, int i, int j)
{
    int a;
    // int b;

    a = 0;
    if (data->map[i][j] == '0' || data->map[i][j] == 'C' || data->map[i][j] == 'E' || data->map[i][j] != '1')
    {
        if (data->map[i][j] == 'C')
            data->collect--;
        if (data->map[i][j] == 'E')
            data->exitss--;
        data->map[i][j] = '1';
        flood_fill(data, i + 1, j);
        flood_fill(data, i - 1, j);
        flood_fill(data, i, j + 1);
        flood_fill(data, i, j - 1);
    }
}
