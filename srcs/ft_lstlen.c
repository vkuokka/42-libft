/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:04:11 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/25 14:49:30 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **alst)
{
	size_t	i;
	t_list	*cur_list;

	i = 0;
	cur_list = *alst;
	while (cur_list)
	{
		i++;
		cur_list = cur_list->next;
	}
	return (i);
}
