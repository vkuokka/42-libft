/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:17:39 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 16:47:02 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ctypes.h"
#include "strings.h"
#include "numbers.h"
#include <unistd.h>

static char	*parse_c_padding(char *print, t_memo *memo)
{
	int				i;
	char			*tmp;
	char			*pad;
	char			c;

	i = ft_atoi(memo->width) - ft_strlen(print);
	if (!memo->width || (0 > i))
		return (print);
	c = ' ';
	if (memo->zero && !memo->minus)
		c = '0';
	pad = ft_strnew(i);
	while (i > 0)
		pad[--i] = c;
	tmp = print;
	if (memo->minus)
		print = ft_strjoin(print, pad);
	else
		print = ft_strjoin(pad, print);
	free(pad);
	free(tmp);
	return (print);
}

int	parse_c(int c, t_memo *memo)
{
	char			*print;
	int				len;

	print = ft_strnew(1);
	if (c == '\0')
		print[0] = 'x';
	else
		print[0] = c;
	print = parse_c_padding(print, memo);
	if (c == '\0')
	{
		len = ft_strlen(print);
		*ft_strchr(print, 'x') = '\0';
		write(1, print, len);
		free(print);
		return (len);
	}
	return (putprint(print, memo->fd));
}
