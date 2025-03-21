/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:36:37 by yseddouk          #+#    #+#             */
/*   Updated: 2024/10/19 15:13:15 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	size_t				i;

	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	if (pdest < psrc || pdest >= psrc + n)
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			pdest[n] = psrc[n];
		}
	}
	return (dest);
}
