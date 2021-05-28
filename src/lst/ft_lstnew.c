/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:48:05 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:23:16 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "memory.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		return (node);
	}
	node->content = (void *)malloc(content_size);
	if (!node->content)
	{
		free(node);
		return (NULL);
	}
	node->content = ft_memmove(node->content, content, content_size);
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
