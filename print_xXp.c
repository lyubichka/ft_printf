/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xXp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:07:26 by vlyubick          #+#    #+#             */
/*   Updated: 2022/03/04 22:28:32 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(unsigned long long n)
{
	int	 len;

	len = 0;
	if (n == 0)
		return (ft_prints("0x0"));
	len += ft_prints("0x");
	ft_schet(n);
	len += nbrlenx(n);
	return (len);
}

void	ft_schet(unsigned long long n)
{
	if (n >= 16)
		ft_schet(n / 16);
	ft_printc("0123456789abcdef"[n % 16]);
}

int	nbrlenx(unsigned long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_printx(long long int x, char c)
{
	int	len;

	len = 0;
	if (x >= 16)
		len += ft_printx(x / 16, c);
	if (c == 'x')
		len += ft_printc("0123456789abcdef"[x % 16]);
	if (c == 'X')
		len += ft_printc("0123456789ABCDEF"[x % 16]);
	return (len);
}
