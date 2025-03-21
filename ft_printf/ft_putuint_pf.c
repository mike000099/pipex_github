/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:43:30 by yseddouk          #+#    #+#             */
/*   Updated: 2025/01/10 14:02:07 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putuint_pf(unsigned int num, size_t *counter)
{
	char	buffer[11];
	int		i;

	if (num == 0)
	{
		ft_putchar_pf('0', counter);
		return ;
	}
	i = 0;
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar_pf(buffer[i], counter);
	}
}
