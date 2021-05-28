/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:21:04 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:07:23 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		if (hay[i] == needle[j])
		{
			while (hay[i + j] == needle[j] && (i + j) < len)
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
