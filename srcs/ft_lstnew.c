/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:48:05 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/26 12:21:21 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)ft_memalloc(sizeof(*node))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		return (node);
	}
	if (!(node->content = (void *)ft_memalloc(content_size)))
		return (NULL);
	node->content = ft_memmove(node->content, content, content_size);
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
