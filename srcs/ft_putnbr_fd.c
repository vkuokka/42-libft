/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:09:23 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/26 12:21:32 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long n2;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = n2 * -1;
	}
	if (n2 < 10)
		ft_putchar_fd(n2 + '0', fd);
	else
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putnbr_fd(n2 % 10, fd);
	}
}
