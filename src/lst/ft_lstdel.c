/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:10:42 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:23:55 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur_list;
	t_list	*next_list;

	if (!alst)
		return ;
	cur_list = *alst;
	while (cur_list)
	{
		next_list = cur_list->next;
		del(cur_list->content, cur_list->content_size);
		free(cur_list);
		cur_list = next_list;
	}
	*alst = NULL;
}
