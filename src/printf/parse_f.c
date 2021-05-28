/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:18:05 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:36:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "strings.h"
#include "numbers.h"
#include "swap.h"

static char	*parse_f_padding(char *print, t_memo *memo)
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
	free(pad);
	free(tmp);
	return (print);
}

static char	*parse_f_precision(char *print, t_memo *memo)
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
		if (memo->zero)
			memo->zero = 0;
	}
	return (print);
}

static char	*parse_f_signs(char *print, t_memo *memo)
{
	char			*tmp;

	if (print[0] == '-')
		return (print);
	else if (memo->plus)
	{
		tmp = print;
		print = ft_strjoin("+", print);
		free(tmp);
	}
	else if (memo->space)
	{
		tmp = print;
		print = ft_strjoin(" ", print);
		free(tmp);
	}
	return (print);
}

static char	*parse_f_length(va_list last, t_memo *memo)
{
	char			*pos;
	int				precision;

	if (memo->precision)
		precision = ft_atoi(memo->precision + 1);
	else
		precision = 6;
	pos = ft_strchr(memo->length, 'L');
	if (pos)
		return (ft_ftoa((long double)va_arg(last, long double), precision));
	pos = ft_strchr(memo->length, 'l');
	if (pos)
		return (ft_ftoa((double)va_arg(last, double), precision));
	return (ft_ftoa((double)va_arg(last, double), precision));
}

int	parse_f(va_list last, t_memo *memo)
{
	char			*print;

	print = parse_f_length(last, memo);
	if (!memo->hash && print[ft_strlen(print) - 1] == '.')
		print[ft_strlen(print) - 1] = '\0';
	print = parse_f_precision(print, memo);
	print = parse_f_signs(print, memo);
	print = parse_f_padding(print, memo);
	return (putprint(print, memo->fd));
}
