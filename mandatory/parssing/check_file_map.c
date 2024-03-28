/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:58:17 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/28 08:27:39 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_file_extention(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 4 || file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b' || file[i - 4] != '.')
	{
		ft_printf("Error, File extention is not .ber\n");
		exit(0);
	}
}
