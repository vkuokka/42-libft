/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:07:35 by vkuokka           #+#    #+#             */
/*   Updated: 2020/01/20 12:10:36 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	round(int precision, long double f)
{
	long double	round;
	int			d;

	round = 0.5;
	if (f < 0)
		round *= -1;
	d = 0;
	while (d++ < precision)
		round /= 10.0;
	return (round);
}

char				*ft_ftoa(long double f, int precision, int afterpoint)
{
	unsigned long long	dec;
	char				*ipart;
	char				*fpart;
	char				*joint;
	int					i;

	f = f + round(precision, f);
	f *= (f < 0) ? -1 : 1;
	dec = f;
	ipart = ft_itoa(dec);
	f = precision ? (f - dec) : 0;
	fpart = ft_strnew(precision + 2);
	fpart[0] = (afterpoint) ? '.' : '\0';
	i = 1;
	while (precision-- > 0)
	{
		f *= 10;
		dec = f;
		f -= dec;
		fpart[i++] = dec + '0';
	}
	joint = ft_strjoin(ipart, fpart);
	free(fpart);
	free(ipart);
	return (joint);
}
