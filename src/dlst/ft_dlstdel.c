/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:10:42 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:25:16 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*current;
	t_dlist	*next;

	if (!alst)
		return ;
	current = *alst;
	while (current)
	{
		next = current->next;
		del(current->content, current->content_size);
		free(current);
		current = next;
	}
	*alst = NULL;
}
