/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:09:44 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:48:39 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	ft_print_bits(uint64_t bits, int len)
{
	uint64_t	bit;

	while (len--)
	{
		bit = (bits >> len & 1) + '0';
		write(1, &bit, 1);
		if (len % 8 == 0)
			write(1, " ", 1);
	}
}
