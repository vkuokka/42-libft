/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:15:12 by vkuokka           #+#    #+#             */
/*   Updated: 2020/05/13 19:09:38 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "string.h"

void		*ft_memalloc(size_t size)
{
	void	*area;

	area = (void *)malloc(size);
	if (!area)
		return (NULL);
	ft_bzero(area, size);
	return (area);
}
