/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:48:55 by yseddouk          #+#    #+#             */
/*   Updated: 2024/10/19 16:36:37 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*create_empty_substr(void)
{
	char	*sub_str;

	sub_str = (char *)malloc(1);
	if (sub_str)
		sub_str[0] = '\0';
	return (sub_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub_str;
	size_t			actual_len;

	i = 0;
	if (!s || start >= (unsigned int)ft_strlen(s))
	{
		return (create_empty_substr());
	}
	actual_len = ft_strlen(s) - start;
	if (len > actual_len)
		len = actual_len;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
	{
		return (NULL);
	}
	while (i < len && s[start + i] != '\0')
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
