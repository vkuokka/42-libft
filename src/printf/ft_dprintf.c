/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesa <vesa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 00:19:23 by vkuokka           #+#    #+#             */
/*   Updated: 2021/02/24 14:56:48 by vesa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	last;
	int		p;

	va_start(last, format);
	p = 0;
	while (*format)
	{
		if (*format == '%')
			format = pfparse(fd, format, last, &p);
		else
		{
			write(fd, format, 1);
			p++;
		}
		if (*format)
			format++;
	}
	va_end(last);
	return (p);
}
