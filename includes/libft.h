/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:38:55 by vkuokka           #+#    #+#             */
/*   Updated: 2020/05/15 10:24:54 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "ctype.h"
# include "string.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa(long long n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_swap(int *a, int *b);
void				ft_swap_char(char *a, char *b);
void				ft_swap_str(char **a, char **b);
void				ft_del(void *content, size_t size);
size_t				ft_lstlen(t_list **alst);
char				*ft_itoa_base(unsigned long long value, int base);
char				*ft_ftoa(long double f, int pre);
int					ft_count_digits(long long nbr);
void				ft_arriter(char **arr, void (*f)(const char *));
void				ft_arrfree(char **arr);

#endif
