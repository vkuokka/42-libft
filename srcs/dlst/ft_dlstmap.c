/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:35:29 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/24 21:50:31 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlist		*ft_lstmap(t_dlist *dlst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist	*node;
	t_dlist	*head;

	if (!dlst || !f)
		return (NULL);
	node = f(dlst);
	head = node;
	while (dlst->next)
	{
		dlst = dlst->next;
		if (!(node->next = f(dlst)))
			return (NULL);
		node = node->next;
	}
	return (head);
}
