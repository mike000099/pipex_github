/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:02:01 by yseddouk          #+#    #+#             */
/*   Updated: 2024/10/19 16:49:33 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static	int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*ft_copy_trimmed_string(char const *s1, int start, int end)
{
	int		i;
	int		new_len;
	char	*new_str;

	i = 0;
	new_len = (end - start) + 1;
	if (new_len <= 0)
		return (ft_strdup(""));
	new_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < new_len)
	{
		new_str[i] = s1[start + i];
		i++;
	}
	new_str[new_len] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_copy_trimmed_string(s1, start, end));
}
