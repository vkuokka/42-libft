/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:00:32 by vkuokka           #+#    #+#             */
/*   Updated: 2020/05/15 10:09:12 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*csrc;
	unsigned char		*cdst;

	i = -1;
	csrc = (const unsigned char*)src;
	cdst = (unsigned char*)dst;
	while (++i < n)
		cdst[i] = csrc[i];
	return (dst);
}
