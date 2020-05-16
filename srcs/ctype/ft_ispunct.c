/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:21:59 by vkuokka           #+#    #+#             */
/*   Updated: 2020/05/13 16:39:23 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

int ft_ispunct(int c)
{
	if (ft_isgraph(c) && !ft_isalnum(c))
		return (1);
	return (0);
}