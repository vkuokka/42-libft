/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:15:12 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:22:45 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = (void *)malloc(size);
	if (!area)
		return (NULL);
	ft_bzero(area, size);
	return (area);
}
