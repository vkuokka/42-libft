/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:20:54 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/18 16:07:43 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i && s[i] != c)
	{
		i--;
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}
