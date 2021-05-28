/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:35:29 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:23:48 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	node = f(lst);
	begin = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = f(lst);
		if (!node->next)
			return (NULL);
		node = node->next;
	}
	return (begin);
}
