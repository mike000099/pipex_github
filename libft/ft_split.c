/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:40:21 by yseddouk          #+#    #+#             */
/*   Updated: 2024/10/23 17:43:06 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_freeup(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	word;
	int	in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (in_word == 0)
			{
				word++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
		i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, const char *str, int start, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		word[i] = str[start + i];
		i++;
	}
	word[length] = '\0';
}

static char	*ft_stralloc(const char *str, char c, int *k)
{
	char	*word;
	int		length;
	int		start;

	length = 0;
	start = *k;
	while (str[*k] == c && str[*k] != '\0')
	{
		(*k)++;
	}
	start = *k;
	while (str[*k] != c && str[*k] != '\0')
	{
		length++;
		(*k)++;
	}
	if (length == 0)
	{
		return (NULL);
	}
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	ft_strcpy(word, str, start, length);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		pos;
	int		word_count;

	i = 0;
	pos = 0;
	if (str == NULL)
		return (NULL);
	word_count = ft_wordcount(str, c);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (strs == NULL)
		return (NULL);
	strs[word_count] = NULL;
	while (i < word_count)
	{
		strs[i] = ft_stralloc(str, c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs, i);
			return (NULL);
		}
		i++;
	}
	return (strs);
}
