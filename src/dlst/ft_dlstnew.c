/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:48:05 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:24:27 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"
#include "memory.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*node;

	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		node->prev = NULL;
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
	node->prev = NULL;
	return (node);
}
