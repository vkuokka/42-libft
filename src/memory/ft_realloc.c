/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:13:16 by vkuokka           #+#    #+#             */
/*   Updated: 2021/05/28 18:20:27 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <memory.h>

void	*ft_realloc(void *ptr, size_t old_s, size_t new_s)
{
	void	*new;

	if (!ptr)
		return (NULL);
	new = ft_memalloc(new_s + 1);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	if (old_s < new_s)
		ft_memcpy(new, ptr, old_s);
	else
		ft_memcpy(new, ptr, new_s);
	free(ptr);
	return (new);
}
