/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:33:04 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 14:54:30 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(s2, s1[i]))
			break ;
		i++;
	}
	return (i);
}
