/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 12:02:02 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:32:25 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H

# define PRINT_H

# include <unistd.h>
# include <stdint.h>

void	ft_print_bits(uint64_t bits, int len);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);

#endif
