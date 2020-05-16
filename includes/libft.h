/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:38:55 by vkuokka           #+#    #+#             */
/*   Updated: 2020/05/16 20:50:43 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

int		ft_atoi(const char *str);

char	*ft_itoa(long long n);
void	ft_swap(int *a, int *b);
void	ft_swap_char(char *a, char *b);
void	ft_swap_str(char **a, char **b);
char	*ft_itoa_base(unsigned long long value, int base);
char	*ft_ftoa(long double f, int pre);
int		ft_count_digits(long long nbr);
void	ft_arriter(char **arr, void (*f)(const char *));
void	ft_arrfree(char **arr);

#endif
