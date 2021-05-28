/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 12:02:26 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:31:12 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H

# define ARRAYS_H

# include <stddef.h>

void	ft_arrfree(char **arr);
void	ft_arriter(char **arr, void (*f)(const char *));
size_t	ft_arrlen(char **array, size_t max);

#endif
