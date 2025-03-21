/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:50:25 by yseddouk          #+#    #+#             */
/*   Updated: 2024/10/19 15:19:51 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
		{
			return ((char *)(s + (i - 1)));
		}
		i--;
	}
	return (NULL);
}
