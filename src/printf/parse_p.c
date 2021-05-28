/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:07:07 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:25:08 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "strings.h"
#include "numbers.h"
#include "swap.h"

static char	*parse_p_padding(char *p, t_memo *memo)
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

int	parse_p(va_list last, t_memo *memo)
{
	char			*tmp;
	char			*print;

	tmp = ft_itoa_base(va_arg(last, unsigned long long), 16);
	if (tmp[0] == '0' && memo->precision && !ft_atoi(memo->precision + 1))
		tmp[0] = '\0';
	print = ft_strjoin("0x", tmp);
	free(tmp);
	print = parse_p_padding(print, memo);
	return (putprint(print, memo->fd));
}
