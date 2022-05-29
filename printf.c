/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:48:44 by vlyubick          #+#    #+#             */
/*   Updated: 2022/03/04 20:50:53 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{	
	va_list		list;
	int			res;
	int			ret;

	va_start(list, format);
	res = 0;
	ret = 0;
	while (format[res] != '\0')
	{
		if (format[res] == '%' && format[res + 1])
		{
			ret += ft_get_format(list, format[res + 1]);
			res++;
		}
		else
			ret += ft_printc(format[res]);
		res++;
	}
	va_end(list);
	return (ret);
}

int	ft_printc(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printper(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_get_format(va_list list, char format)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_printc(va_arg(list, int));
	else if (format == '%')
		ret += ft_printper();
	else if (format == 's')
		ret += ft_prints(va_arg(list, char *));
	else if (format == 'd' || format == 'i')
		ret += ft_printd(va_arg(list, int));
	else if (format == 'u')
		ret += ft_printu(va_arg(list, unsigned int));
	else if (format == 'X' || format == 'x')
		ret += ft_printx(va_arg(list, unsigned int), format);
	else if (format == 'p')
		ret += ft_printp(va_arg(list, unsigned long long));
	else
		ret += ft_printc(format);
	return (ret);
}
