/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:13:16 by vkuokka           #+#    #+#             */
/*   Updated: 2021/02/24 15:17:43 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <memory.h>

void		*ft_realloc(void *ptr, size_t old_s, size_t new_s)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(new_s + 1)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, old_s < new_s ? old_s : new_s);
	free(ptr);
	return (new);
}