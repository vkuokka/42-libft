/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:17:07 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:07:54 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

char	*ft_strnew(size_t size)
{
	char	*area;

	area = (char *)malloc(sizeof(char) * (size + 1));
	if (!area)
		return (NULL);
	ft_memset(area, '\0', (size + 1));
	return (area);
}
