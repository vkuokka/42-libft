/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:25:51 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:25:21 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstaddback(t_dlist **alst, t_dlist *new)
{
	t_dlist	*current;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
		current->next->prev = current;
	}
}
