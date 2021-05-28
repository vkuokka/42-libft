/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:39:05 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:08:26 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = ft_strlen(dst);
	res = 0;
	res = ft_strlen(src);
	if (dstsize <= i)
		res += dstsize;
	else
		res += i;
	j = 0;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
