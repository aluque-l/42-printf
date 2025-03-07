/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-l <aluque-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:23:37 by aluque-l          #+#    #+#             */
/*   Updated: 2024/12/04 13:51:47 by aluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long ptr, int *result)
{
	if (!ptr)
		ft_putstr("(nil)", result);
	else
	{
		ft_putstr("0x", result);
		ft_puthex((unsigned long)ptr, 'x', result);
	}
}

void	ft_putstr(char *s, int *result)
{
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchar(*s++, result);
}

void	ft_uns_putnbr(unsigned int n, int *result)
{
	if (n >= 10)
		ft_putnbr(n / 10, result);
	ft_putchar((n % 10) + '0', result);
}

void	ft_putnbr( int n, int *result)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", result);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', result);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr(n / 10, result);
		ft_putchar((n % 10) + '0', result);
	}
}

void	ft_puthex(unsigned long n, char format, int *result)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16 && ((format == 'x') || (format == 'X')))
		ft_puthex(n / 16, format, result);
	ft_putchar(base[n % 16], result);
}
