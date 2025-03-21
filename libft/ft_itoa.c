/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:15:24 by yseddouk          #+#    #+#             */
/*   Updated: 2024/10/19 17:21:43 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static	int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	void	ft_convert_to_string(char *arr, int n, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		arr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	int		i;
	int		is_negative;

	len = ft_length(n);
	i = len - 1;
	is_negative = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		is_negative = 1;
		n = -n;
	}
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	ft_convert_to_string(arr, n, len);
	if (is_negative)
		arr[0] = '-';
	return (arr);
}
