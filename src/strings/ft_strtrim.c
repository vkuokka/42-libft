/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:17:28 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 14:54:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "ctypes.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_isspace(s[start]) && s[start])
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	end = ft_strlen(s);
	while (ft_isspace(s[end - 1]))
		end--;
	if (start == end)
		return (ft_strnew(0));
	return (ft_strsub(s, (unsigned int)start, end - start));
}
