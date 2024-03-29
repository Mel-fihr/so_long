/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:17:39 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/24 04:29:23 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_data *data, int i, int j)
{
	if (i < 0 || i >= data->height || j < 0 || j >= data->width)
		return ;
	if (data->map[i][j] == 'E')
		data->map[i][j] = '1';
	if (data->map[i][j] != '1')
	{
		data->map[i][j] = '1';
		flood_fill(data, i + 1, j);
		flood_fill(data, i - 1, j);
		flood_fill(data, i, j + 1);
		flood_fill(data, i, j - 1);
	}
}

void	init(t_ecp *ecp)
{
	ecp->i = 0;
	ecp->j = 0;
	ecp->c = 0;
	ecp->e = 0;
	ecp->p = 0;
}
