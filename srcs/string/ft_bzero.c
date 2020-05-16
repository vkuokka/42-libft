/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:01:54 by vkuokka           #+#    #+#             */
/*   Updated: 2020/05/16 21:02:52 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*buff;
	size_t			i;

	buff = (unsigned char*)s;
	i = -1;
	while (++i < n)
		buff[i] = 0;
}
