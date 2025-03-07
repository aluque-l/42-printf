/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-l <aluque-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:39:25 by aluque-l          #+#    #+#             */
/*   Updated: 2025/02/27 14:19:16 by aluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

static void	ft_handle_format(char c, va_list args, int *result)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), result);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), result);
	else if (c == 'p')
		ft_putptr(va_arg(args, unsigned long long), result);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int), result);
	else if (c == 'u')
		ft_uns_putnbr((unsigned int)va_arg(args, unsigned int), result);
	else if (c == 'x' || c == 'X')
		ft_puthex((unsigned int)va_arg(args, unsigned int), c, result);
	else if (c == '%')
		ft_putchar('%', result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			ft_handle_format(format[++i], args, &result);
		else
			ft_putchar(format[i], &result);
		i++;
	}
	va_end(args);
	return (result);
}

/*int main (void)
{
	ft_printf(NULL);
 	printf("%c", '\n');
	printf("%c", 'b');
	printf("%c", '\n'); 
}*/
