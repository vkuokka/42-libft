/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:17:50 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:40:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "strings.h"
#include "numbers.h"
#include "swap.h"

static char	*parse_di_padding(char *print, t_memo *memo)
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
	{
		if (print[0] == '-' && pad[0] == '0')
			ft_swap_char(&print[0], &pad[0]);
		if (print[0] == '+' && pad[0] == '0')
			ft_swap_char(&print[0], &pad[0]);
		if (print[0] == ' ' && pad[0] == '0')
			ft_swap_char(&print[0], &pad[0]);
		print = ft_strjoin(pad, print);
	}
	free(tmp);
	free(pad);
	return (print);
}

static char	*parse_di_precision(char *print, t_memo *memo)
{
	size_t			i;
	char			*buffer;
	char			*tmp;

	if (!memo->precision)
		return (print);
	i = ft_atoi(memo->precision + 1);
	if (i > ft_strlen(print))
	{
		i = i - ft_strlen(print);
		if (print[0] == '-')
			i++;
		buffer = ft_strnew(i);
		while (i > 0)
			buffer[--i] = '0';
		if (print[0] == '-')
			ft_swap_char(&print[0], &buffer[0]);
		tmp = print;
		print = ft_strjoin(buffer, print);
		free(tmp);
		free(buffer);
	}
	else if (print[0] == '0')
		print[0] = '\0';
	if (memo->zero)
		memo->zero = 0;
	return (print);
}

static char	*parse_di_signs(char *print, t_memo *memo)
{
	char			*tmp;

	if (print[0] == '-')
		return (print);
	else if (memo->plus)
	{
		tmp = print;
		print = ft_strjoin("+", print);
		free(tmp);
		return (print);
	}
	else if (memo->space)
	{
		tmp = print;
		print = ft_strjoin(" ", print);
		free(tmp);
		return (print);
	}
	return (print);
}

static char	*parse_di_length(va_list last, t_memo *memo)
{
	char			*pos;

	pos = ft_strchr(memo->length, 'h');
	if (pos)
	{
		if (*(pos + 1) == 'h')
			return (ft_itoa((signed char)va_arg(last, int)));
		else
			return (ft_itoa((short int)va_arg(last, int)));
	}
	pos = ft_strchr(memo->length, 'l');
	if (pos)
	{
		if (*(pos + 1) == 'l')
			return (ft_itoa((long long)va_arg(last, long long)));
		else
			return (ft_itoa((long)va_arg(last, long)));
	}
	return (ft_itoa((int)va_arg(last, int)));
}

int	parse_di(va_list last, t_memo *memo)
{
	char			*print;

	print = parse_di_length(last, memo);
	print = parse_di_precision(print, memo);
	print = parse_di_signs(print, memo);
	print = parse_di_padding(print, memo);
	return (putprint(print, memo->fd));
}
