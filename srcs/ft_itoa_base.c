/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 11:22:49 by vkuokka           #+#    #+#             */
/*   Updated: 2020/01/03 15:23:34 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int value, int base)
{
	int		len;

	len = 1;
	if (value < 0)
		len++;
	while (value /= base)
		len++;
	return (len);
}

static char	*ft_rev(char *str)
{
	char	*rev;
	int		i;
	int		j;

	if (!(rev = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i])
	{
		rev[i] = str[j];
		i++;
		j--;
	}
	free(str);
	return (rev);
}

static char	ft_alpha(int set)
{
	char	*alpha;

	alpha = "ABCDEF";
	return (alpha[set % 10]);
}

char		*ft_itoa_base(int value, int base)
{
	int		neg;
	char	*str;
	int		i;
	int		set;

	if (base < 2 || base > 16)
		return (NULL);
	neg = value < 0 && base == 10 ? 1 : 0;
	value < 0 ? value *= -1 : 0;
	if (!(str = ft_strnew((ft_len(value, base) + neg))))
		return (NULL);
	i = 0;
	while (value > 0)
	{
		set = value % base;
		if (set > 9)
			str[i] = ft_alpha(set);
		else
			str[i] = set + '0';
		value /= base;
		i++;
	}
	neg ? str[i] = '-' : 0;
	return (ft_rev(str));
}
