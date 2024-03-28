/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:53:50 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/23 22:06:18 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_exit(t_all *all, int i, int j)
{
	if (all->data->map[i][j] == 'E' && all->data->collect == 0)
	{
		ft_printf("You win\n");
		exit(0);
	}
}
