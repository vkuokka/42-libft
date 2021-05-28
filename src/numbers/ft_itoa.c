/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:14:35 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 16:55:23 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static int	length(long long n)
{
	int	count;

	count = 1;
	while (1)
	{
		n /= 10;
		if (n < 10)
			break ;
		count++;
	}
	return (count);
}

char	*ft_itoa(long long n)
{
	size_t			i;
	char			*strnb;
	unsigned int	neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n + 1 == -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	strnb = ft_strnew(neg + length(n));
	if (!strnb)
		return (NULL);
	i = neg + length(n) - 1;
	while (n != 0)
	{
		strnb[i--] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		strnb[0] = '-';
	return (strnb);
}
