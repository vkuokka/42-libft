/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:31:21 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/24 21:54:04 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_lstiter(t_dlist *dlst, void (*f)(t_dlist *elem))
{
	if (!dlst || !f)
		return ;
	while (dlst)
	{
		f(dlst);
		dlst = dlst->next;
	}
}
