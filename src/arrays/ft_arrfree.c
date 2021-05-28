/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 10:56:06 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:26:42 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	ft_arrfree(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		ft_strdel(&arr[i]);
	free(arr);
}
