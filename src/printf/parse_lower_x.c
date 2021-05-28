/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lower_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:18:22 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:31:39 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "strings.h"
#include "numbers.h"
#include "swap.h"

static char	*parse_lower_x_padding(char *p, t_memo *memo)
{
	int				i;
	char			*tmp;
	char			*ad;
	char			c;

	i = ft_atoi(memo->width) - ft_strlen(p);
	if (!memo->width || (0 > i))
		return (p);
	c = ' ';
	if (memo->zero && !memo->minus)
		c = '0';
	ad = ft_strnew(i);
	while (i > 0)
		ad[--i] = c;
	tmp = p;
	if (memo->minus)
		p = ft_strjoin(p, ad);
	else
	{
		if (ad[0] == '0' && ad[1] && p[1] == 'x')
			ft_swap_char(&p[1], &ad[1]);
		if (ad[0] == '0' && !ad[1] && p[1] == 'x')
			ft_swap_char(&p[1], &p[0]);
		p = ft_strjoin(ad, p);
	}
	free(ad);
	free(tmp);
	return (p);
}

static char	*parse_lower_x_precision(char *print, t_memo *memo)
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
		buffer = ft_strnew(i);
		while (i > 0)
			buffer[--i] = '0';
		tmp = print;
		print = ft_strjoin(buffer, print);
		free(tmp);
		free(buffer);
	}
	else if (print[0] == '0' && !memo->hash)
		print[0] = '\0';
	if (memo->zero)
		memo->zero = 0;
	return (print);
}

static char	*parse_lower_x_signs(char *print, t_memo *memo)
{
	char			*tmp;

	if (memo->hash)
	{
		tmp = print;
		print = ft_strjoin("0x", print);
		free(tmp);
	}
	return (print);
}

static char	*parse_lower_x_length(va_list last, t_memo *memo)
{
	char			*pos;

	pos = ft_strchr(memo->length, 'h');
	if (pos)
	{
		if (*(pos + 1) == 'h')
			return (ft_itoa_base((unsigned char)
					va_arg(last, unsigned int), 16));
		else
			return (ft_itoa_base((unsigned short int)
					va_arg(last, unsigned int), 16));
	}
	pos = ft_strchr(memo->length, 'l');
	if (pos)
	{
		if (*(pos + 1) == 'l')
			return (ft_itoa_base((unsigned long long)
					va_arg(last, unsigned long long), 16));
		else
			return (ft_itoa_base((unsigned long)
					va_arg(last, unsigned long), 16));
	}
	return (ft_itoa_base((unsigned int)va_arg(last, unsigned int), 16));
}

int	parse_lower_x(va_list last, t_memo *memo)
{
	char			*print;

	print = parse_lower_x_length(last, memo);
	if (print[0] == '0')
		memo->hash = 0;
	print = parse_lower_x_precision(print, memo);
	print = parse_lower_x_signs(print, memo);
	print = parse_lower_x_padding(print, memo);
	return (putprint(print, memo->fd));
}
