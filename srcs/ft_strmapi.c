/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:16:50 by vkuokka           #+#    #+#             */
/*   Updated: 2019/10/28 13:38:40 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (!(fresh = (char *)ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
