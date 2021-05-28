/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:47:55 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 14:54:22 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char *)hay);
	while (hay[i])
	{
		if (hay[i] == needle[j])
		{
			while (hay[i + j] == needle[j])
			{
				if (!needle[j + 1])
					return ((char *)hay + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
