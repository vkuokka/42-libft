# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 11:41:03 by vkuokka           #+#    #+#              #
#    Updated: 2020/05/13 17:25:32 by vkuokka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS =	srcs/ft_bzero.c \
		srcs/ft_memccpy.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_memcpy.c \
		srcs/ft_memmove.c \
		srcs/ft_memset.c \
		srcs/ft_strlen.c \
		srcs/ft_strdup.c \
		srcs/ft_strcpy.c \
		srcs/ft_strcat.c \
		srcs/ft_strncat.c \
		srcs/ft_strlcat.c \
		srcs/ft_strchr.c \
		srcs/ft_strrchr.c \
		srcs/ft_strstr.c \
		srcs/ft_strnstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strncmp.c \
		srcs/ft_atoi.c \
		srcs/ft_toupper.c \
		srcs/ft_tolower.c \
		srcs/ft_strtrim.c \
		srcs/ft_strsub.c \
		srcs/ft_strnew.c \
		srcs/ft_strnequ.c \
		srcs/ft_strmapi.c \
		srcs/ft_strmap.c \
		srcs/ft_strjoin.c \
		srcs/ft_striteri.c \
		srcs/ft_striter.c \
		srcs/ft_strdel.c \
		srcs/ft_strclr.c \
		srcs/ft_memdel.c \
		srcs/ft_memalloc.c \
		srcs/ft_itoa.c \
		srcs/ft_putstr.c \
		srcs/ft_putendl.c \
		srcs/ft_putnbr.c \
		srcs/ft_putchar.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_strsplit.c \
		srcs/ft_lstnew.c \
		srcs/ft_lstdelone.c \
		srcs/ft_lstdel.c \
		srcs/ft_lstadd.c \
		srcs/ft_lstiter.c \
		srcs/ft_lstmap.c \
		srcs/ft_strequ.c \
		srcs/ft_strncpy.c \
		srcs/ft_lstaddback.c \
		srcs/ft_swap.c \
		srcs/ft_swap_char.c \
		srcs/ft_swap_str.c \
		srcs/ft_del.c \
		srcs/ft_lstlen.c \
		srcs/ft_itoa_base.c \
		srcs/ft_strspn.c \
		srcs/ft_strclen.c \
		srcs/ft_ftoa.c \
	   	srcs/ft_count_digits.c \
		srcs/ft_arriter.c \
		srcs/ft_arrfree.c \
		srcs/ctype/ft_isalnum.c \
		srcs/ctype/ft_isalpha.c \
		srcs/ctype/ft_isascii.c \
		srcs/ctype/ft_iscntrl.c \
		srcs/ctype/ft_isdigit.c \
		srcs/ctype/ft_isgraph.c \
		srcs/ctype/ft_islower.c \
		srcs/ctype/ft_isprint.c \
		srcs/ctype/ft_ispunct.c \
		srcs/ctype/ft_isspace.c \
		srcs/ctype/ft_isspace.c \
		srcs/ctype/ft_isupper.c \

OBJ =	$(notdir $(SRCS:.c=.o))

FLAGS = -Wall -Werror -Wextra

INCL =	includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(INCL) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
