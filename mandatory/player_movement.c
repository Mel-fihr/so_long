/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:19:21 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/28 03:41:39 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_all *arg)
{
	check_exit (arg, arg->data->p_y - 1, arg->data->p_x);
	if (arg->data->map[arg->data->p_y - 1][arg->data->p_x] == '0'
		|| arg->data->map[arg->data->p_y - 1][arg->data->p_x] == 'C')
	{
		up(arg, arg->data->p_y, arg->data->p_x);
		ft_printf("move: %d\n", ++arg->data->move);
		arg->data->p_y -= 1;
	}
}

static void	move_down(t_all *arg)
{
	check_exit (arg, arg->data->p_y + 1, arg->data->p_x);
	if (arg->data->map[arg->data->p_y + 1][arg->data->p_x] == '0'
		|| arg->data->map[arg->data->p_y + 1][arg->data->p_x] == 'C')
	{
		down(arg, arg->data->p_y, arg->data->p_x);
		ft_printf("move: %d\n", ++arg->data->move);
		arg->data->p_y += 1;
	}
}

static void	move_right(t_all *arg)
{
	check_exit(arg, arg->data->p_y, arg->data->p_x + 1);
	if (arg->data->map[arg->data->p_y][arg->data->p_x + 1] == '0'
		|| arg->data->map[arg->data->p_y][arg->data->p_x + 1] == 'C')
	{
		right(arg, arg->data->p_y, arg->data->p_x);
		ft_printf("move: %d\n", ++arg->data->move);
		arg->data->p_x += 1;
	}
}

static void	move_left(t_all *arg)
{
	check_exit(arg, arg->data->p_y, arg->data->p_x - 1);
	if (arg->data->map[arg->data->p_y][arg->data->p_x - 1] == '0'
		|| arg->data->map[arg->data->p_y][arg->data->p_x - 1] == 'C')
	{
		left(arg, arg->data->p_y, arg->data->p_x);
		ft_printf("move: %d\n", ++arg->data->move);
		arg->data->p_x -= 1;
	}
}

int	player_movement(int keycode, t_all *all)
{
	if (keycode == 53)
		exit (0);
	else if (keycode == 126)
		move_up(all);
	else if (keycode == 125)
		move_down(all);
	else if (keycode == 124)
		move_right(all);
	else if (keycode == 123)
		move_left(all);
	return (0);
}
