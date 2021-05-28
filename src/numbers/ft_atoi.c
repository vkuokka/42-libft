/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:01:09 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:17:23 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctypes.h"
#include <stddef.h>

int	ft_atoi(const char *str)
{
	int		sign;
	int		sum;
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum * sign);
}
