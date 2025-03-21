/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:57:43 by yseddouk          #+#    #+#             */
/*   Updated: 2024/10/23 15:57:53 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;

	new_list = NULL;
	while (lst != NULL)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (temp == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		temp->content = f(lst->content);
		temp->next = NULL;
		if (new_list == NULL)
			new_list = temp;
		else
			new_node->next = temp;
		new_node = temp;
		lst = lst->next;
	}
	return (new_list);
}
