/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:14:35 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/26 12:21:14 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_len(int n)
{
	int count;

	count = 1;
	while (n /= 10)
		count++;
	return (count);
}

char		*ft_itoa(int n)
{
	size_t			i;
	char			*strnb;
	unsigned int	neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (ft_isneg(n))
	{
		neg = 1;
		n = n * -1;
	}
	if (!(strnb = ft_strnew(neg + ft_len(n))))
		return (NULL);
	i = neg + ft_len(n) - 1;
	while (n != 0)
	{
		strnb[i--] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		strnb[0] = '-';
	return (strnb);
}
