/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sdi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:48:28 by vlyubick          #+#    #+#             */
/*   Updated: 2022/03/04 20:12:23 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printd(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (ft_prints("-2147483648"));
	if (n < 0)
	{
		ft_printc('-');
		n *= -1;
		len++;
	}
	if (n > 9)
		len += ft_printd(n / 10);
	ft_printc((n % 10) + '0');
	return (len);
}

// int	nbrlen(int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n <= 0)
// 		len++;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

int	ft_printu(unsigned int u)
{
	int	len;

	len = 1;
	if (u > 9)
		len += ft_printu(u / 10);
	ft_printc((u % 10) + '0');
	return (len);
}
