/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:58:44 by yseddouk          #+#    #+#             */
/*   Updated: 2025/01/10 14:02:41 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_hex_length(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static char	*ft_ptr_to_hex(unsigned long num, char *base)
{
	int		len;
	char	*str;
	int		i;
	int		digit;

	len = ft_hex_length(num);
	str = (char *)malloc(len + 1);
	i = len - 1;
	if (str == NULL)
		return (NULL);
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[len] = '\0';
	while (i >= 0)
	{
		digit = num % 16;
		str[i] = base[digit];
		num /= 16;
		i--;
	}
	return (str);
}

void	ft_puthex_pf(unsigned long num, size_t *counter, char *base)
{
	char	*str;

	str = ft_ptr_to_hex(num, base);
	if (str)
	{
		ft_putstr_pf(str, counter);
		free(str);
	}
}
