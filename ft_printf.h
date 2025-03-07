/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-l <aluque-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:39:46 by aluque-l          #+#    #+#             */
/*   Updated: 2024/12/04 13:52:30 by aluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *result);
void	ft_putstr(char *s, int *result);
void	ft_uns_putnbr(unsigned int n, int *result);
void	ft_putnbr(int n, int *result);
void	ft_puthex(unsigned long n, char format, int *result);
void	ft_putptr(unsigned long long ptr, int *result);
int		ft_printf(char const *format, ...);

#endif
