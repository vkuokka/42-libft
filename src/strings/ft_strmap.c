/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:16:26 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:08:19 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	if (!s || !f)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (!fresh)
		return (NULL);
	i = -1;
	while (s[++i])
		fresh[i] = f(s[i]);
	fresh[i] = '\0';
	return (fresh);
}
