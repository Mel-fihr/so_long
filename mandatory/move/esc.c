/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:12:05 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/06 18:03:37 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	esc(t_all *all)
{
	mlx_destroy_window (all->data->mlx, all->data->mlx_win);
	exit (0);
}
