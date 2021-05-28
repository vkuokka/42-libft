/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:04:11 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:24:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

size_t	ft_lstlen(t_list **alst)
{
	size_t	i;
	t_list	*cur_list;

	if (!alst)
		return (0);
	i = 0;
	cur_list = *alst;
	while (cur_list)
	{
		i++;
		cur_list = cur_list->next;
	}
	return (i);
}
