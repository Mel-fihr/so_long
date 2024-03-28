/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:56:02 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/23 21:57:15 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr(int num)
{
	int	res;

	res = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		res += 1;
		num = -num;
	}
	if (num > 9)
	{
		res += ft_putnbr(num / 10);
		res += ft_putnbr(num % 10);
	}
	if (num <= 9)
		res += ft_printf_char(num + 48);
	return (res);
}
