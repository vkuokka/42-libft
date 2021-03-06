/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:07:48 by vkuokka           #+#    #+#             */
/*   Updated: 2021/02/24 15:07:57 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** finds the first instance of c from the left.
*/

int		ft_lfind(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}