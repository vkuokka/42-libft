/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 11:22:49 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 16:57:19 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static int	length(unsigned long long value, int base)
{
	int	len;

	len = 1;
	while (1)
	{
		value /= base;
		if (value < base)
			break ;
		len++;
	}
	return (len);
}

static char	*reverse(char *str)
{
	char	*rev;
	int		i;
	int		j;

	rev = ft_strnew(ft_strlen(str));
	if (!rev)
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

static char	alpha(unsigned long long set)
{
	char	*alpha;

	alpha = "abcdef";
	return (alpha[set % 10]);
}

char	*ft_itoa_base(unsigned long long value, int base)
{
	char	*str;
	int		i;
	int		set;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	len = length(value, base);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		set = value % base;
		if (set > 9)
			str[i] = alpha(set);
		else
			str[i] = set + '0';
		value /= base;
		i++;
	}
	return (reverse(str));
}
