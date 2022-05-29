/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:08:44 by vlyubick          #+#    #+#             */
/*   Updated: 2022/03/04 21:07:31 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
int			ft_printc(int c);
int			ft_printper(void);
int			ft_get_format(va_list list, const char format);
int			ft_prints(char *str);
int			ft_printd(int n);
int			nbrlen(int n);
int			ft_printu(unsigned int u);
int			ft_printp(unsigned long long n);
void		ft_schet(unsigned long long n);
int			nbrlenx(unsigned long long n);
int			ft_printx(long long int x, char c);

#endif