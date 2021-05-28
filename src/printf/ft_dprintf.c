/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 00:19:23 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:47:25 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_dprintf(int fd, const char *format, ...)
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
