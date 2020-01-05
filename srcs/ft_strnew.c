/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:17:07 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/28 13:19:12 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *area;

	if (!(area = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(area, '\0', (size + 1));
	return (area);
}
