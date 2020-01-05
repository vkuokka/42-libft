/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:47:55 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/28 12:16:26 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j])
			{
				if (!needle[j + 1])
					return ((char *)haystack + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
