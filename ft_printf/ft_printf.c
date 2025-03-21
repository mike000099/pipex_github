/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:28:01 by yseddouk          #+#    #+#             */
/*   Updated: 2025/01/10 14:08:27 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	handle_specifier(char specifier, va_list args, size_t *counter)
{
	if (specifier == 'c')
		ft_putchar_pf(va_arg(args, int), counter);
	else if (specifier == 's')
		ft_putstr_pf(va_arg(args, void *), counter);
	else if (specifier == 'p')
		ft_putptr_pf(va_arg(args, void *), counter);
	else if (specifier == 'i' || specifier == 'd')
		ft_putnbr_pf(va_arg(args, int), counter);
	else if (specifier == 'u')
		ft_putuint_pf(va_arg(args, unsigned), counter);
	else if (specifier == 'x')
		ft_puthex_pf(va_arg(args, unsigned int), counter, "0123456789abcdef");
	else if (specifier == 'X')
		ft_puthex_pf(va_arg(args, unsigned int), counter, "0123456789ABCDEF");
	else if (specifier == '%')
		ft_putchar_pf('%', counter);
	else
		ft_putchar_pf(specifier, counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	counter;

	counter = 0;
	if (str == NULL)
		return (0);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			handle_specifier(*str, args, &counter);
		}
		else
			ft_putchar_pf(*str, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}
