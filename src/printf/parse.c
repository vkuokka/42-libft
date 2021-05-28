/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:17:07 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:47:10 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ctypes.h"
#include "strings.h"
#include "numbers.h"

static t_memo	**initialize_memo(t_memo **memo, int fd)
{
	(*memo) = malloc(sizeof(t_memo));
	(*memo)->hash = 0;
	(*memo)->zero = 0;
	(*memo)->minus = 0;
	(*memo)->plus = 0;
	(*memo)->space = 0;
	(*memo)->width = NULL;
	(*memo)->precision = NULL;
	(*memo)->length = NULL;
	(*memo)->fd = fd;
	return (memo);
}

static size_t	create_wpl(char *fwpl, size_t i, t_memo **memo, char *s)
{
	size_t			len;

	len = ft_strspn(fwpl + i, s);
	if (ft_strequ(s, WIDTH))
		(*memo)->width = ft_strsub(fwpl, i, len);
	if (ft_strequ(s, PRECISION))
		(*memo)->precision = ft_strsub(fwpl, i, len);
	if (ft_strequ(s, LENGTH))
		(*memo)->length = ft_strsub(fwpl, i, len);
	return (len);
}

static const char	*fill_memo(const char *format, t_memo **memo)
{
	size_t			i;
	size_t			round;
	char			*fwpl;

	format++;
	fwpl = ft_strsub(format, 0, ft_strspn(format, FWPL));
	i = 0;
	while (fwpl[i])
	{
		round = i;
		if (fwpl[i] == '#')
			(*memo)->hash = 1;
		if (fwpl[i] == '0')
			(*memo)->zero = 1;
		if (fwpl[i] == '-')
			(*memo)->minus = 1;
		if (fwpl[i] == '+')
			(*memo)->plus = 1;
		if (fwpl[i] == ' ')
			(*memo)->space = 1;
		if (fwpl[i] == '*' || (ft_isdigit(fwpl[i]) && fwpl[i] != 0))
			i += create_wpl(fwpl, i, memo, WIDTH);
		if (fwpl[i] == '.')
			i += create_wpl(fwpl, i, memo, PRECISION);
		if (fwpl[i] == 'h' || fwpl[i] == 'l' || fwpl[i] == 'L')
			i += create_wpl(fwpl, i, memo, LENGTH);
		if (round == i)
			i++;
	}
	free(fwpl);
	return (format + i);
}

static t_memo	*get_wp(t_memo *memo, va_list last)
{
	char			*tmp;
	char			*tmp1;

	if (memo->width && ft_strchr(memo->width, '*'))
	{
		tmp = memo->width;
		memo->width = ft_itoa((va_arg(last, int)));
		free(tmp);
	}
	if (memo->precision && ft_strchr(memo->precision, '*'))
	{
		tmp = memo->precision;
		tmp1 = ft_itoa((va_arg(last, int)));
		memo->precision = ft_strjoin(".", tmp1);
		free(tmp);
		free(tmp1);
	}
	return (memo);
}

const char	*pfparse(int fd, const char *format, va_list last, int *p)
{
	t_memo			*memo;

	format = fill_memo(format, initialize_memo(&memo, fd));
	memo = get_wp(memo, last);
	while (*format == ' ')
		format++;
	if (*format == '%')
		*p += parse_c('%', memo);
	if (*format == 'c')
		*p += parse_c(va_arg(last, int), memo);
	if (*format == 's')
		*p += parse_s(last, memo);
	if (*format == 'p')
		*p += parse_p(last, memo);
	if (*format == 'd')
		*p += parse_di(last, memo);
	if (*format == 'i')
		*p += parse_di(last, memo);
	if (*format == 'o')
		*p += parse_o(last, memo);
	if (*format == 'u')
		*p += parse_u(last, memo);
	if (*format == 'x')
		*p += parse_lower_x(last, memo);
	if (*format == 'X')
		*p += parse_upper_x(last, memo);
	if (*format == 'f')
		*p += parse_f(last, memo);
	if (memo->width)
		free(memo->width);
	if (memo->precision)
		free(memo->precision);
	if (memo->length)
		free(memo->length);
	free(memo);
	return (format++);
}
