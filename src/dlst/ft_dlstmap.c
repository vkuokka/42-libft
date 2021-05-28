/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:35:29 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:24:51 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, t_dlist *(*f)(t_dlist *elem))
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
		node->next = f(dlst);
		if (!node->next)
			return (NULL);
		node = node->next;
	}
	return (head);
}
