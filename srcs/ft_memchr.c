/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:03:55 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/28 11:16:07 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*cs;

	i = 0;
	cs = (const unsigned char *)s;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
