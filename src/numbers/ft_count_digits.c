/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:48:08 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:16:56 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digits(long long nbr)
{
	int	count;

	count = 1;
	while (1)
	{
		nbr /= 10;
		if (nbr < 10)
			break ;
		count++;
	}
	return (count);
}
