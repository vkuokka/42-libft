/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:08:08 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 15:12:12 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "strings.h"
#include <unistd.h>

int	putprint(char *print, int fd)
{
	int	len;

	len = ft_strlen(print);
	write(fd, print, len);
	free(print);
	return (len);
}
