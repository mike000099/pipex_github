/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:54:43 by yseddouk          #+#    #+#             */
/*   Updated: 2025/01/10 14:42:34 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_hex_length(unsigned long ptr_add)
{
	int	len;

	len = 0;
	if (ptr_add == 0)
		return (1);
	while (ptr_add > 0)
	{
		ptr_add /= 16;
		len++;
	}
	return (len);
}

static char	*ft_ptr_to_hex(unsigned long ptr_add)
{
	int		len;
	int		i;
	int		digit;
	char	*str;

	len = ft_hex_length(ptr_add);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		digit = ptr_add % 16;
		if (digit < 10)
			str[i] = digit + '0';
		else
			str[i] = (digit - 10) + 'a';
		ptr_add /= 16;
		i--;
	}
	return (str);
}

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_add;

	if (ptr == NULL)
	{
		ft_putstr_pf("(nil)", counter);
		return ;
	}
	ptr_add = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);
	str = ft_ptr_to_hex(ptr_add);
	if (str != NULL)
	{
		ft_putstr_pf(str, counter);
		free(str);
	}
}
