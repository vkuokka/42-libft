/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesa <vesa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:18:48 by vkuokka           #+#    #+#             */
/*   Updated: 2021/02/24 14:57:00 by vesa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			ft_printf(const char *format, ...)
{
	va_list	last;
	int		p;

	va_start(last, format);
	p = 0;
	while (*format)
	{
		if (*format == '%')
			format = pfparse(1, format, last, &p);
		else
		{
			write(1, format, 1);
			p++;
		}
		if (*format)
			format++;
	}
	va_end(last);
	return (p);
}
