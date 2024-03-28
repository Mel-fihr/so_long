/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:07:55 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/23 21:58:15 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argtype(va_list arg, char c)
{
	int	res;

	res = 0;
	if (c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(arg, int));
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	arg;
	int		i;

	va_start(arg, str);
	i = 0;
	res = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 's'
				|| str[i + 1] == 'c' || str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == 'p' || str[i + 1] == 'i' || str[i + 1] == 'u'
				|| str[i + 1] == '%'))
		{
			res += argtype(arg, str[i + 1]);
			i++;
		}
		else if (str[i] != '%')
			res += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (res);
}
