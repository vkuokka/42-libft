/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:00:32 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:22:18 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*csrc;
	unsigned char		*cdst;

	i = -1;
	csrc = (const unsigned char *)src;
	cdst = (unsigned char *)dst;
	while (++i < n)
		cdst[i] = csrc[i];
	return (dst);
}
