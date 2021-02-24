/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_only.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:02:21 by vesa              #+#    #+#             */
/*   Updated: 2021/02/24 15:05:58 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

size_t		ft_count_digits_only(uintmax_t n, int base)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}