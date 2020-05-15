/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:17:07 by vkuokka           #+#    #+#             */
/*   Updated: 2020/05/15 10:10:57 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char		*ft_strnew(size_t size)
{
	char	*area;

	area = (char *)malloc(sizeof(char) * (size + 1));
	if (!area)
		return (NULL);
	ft_memset(area, '\0', (size + 1));
	return (area);
}
