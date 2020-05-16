# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 11:41:03 by vkuokka           #+#    #+#              #
#    Updated: 2020/05/16 20:56:48 by vkuokka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS =	srcs/array/ft_arrfree.c \
		srcs/array/ft_arriter.c \
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
		srcs/ctype/ft_tolower.c \
		srcs/ctype/ft_toupper.c \
		srcs/integer/ft_atoi.c \
		srcs/integer/ft_count_digits.c \
		srcs/integer/ft_ftoa.c \
		srcs/integer/ft_itoa_base.c \
		srcs/integer/ft_itoa.c \
		srcs/lst/ft_del.c \
		srcs/lst/ft_lstadd.c \
		srcs/lst/ft_lstaddback.c \
		srcs/lst/ft_lstdel.c \
		srcs/lst/ft_lstdelone.c \
		srcs/lst/ft_lstiter.c \
		srcs/lst/ft_lstlen.c \
		srcs/lst/ft_lstmap.c \
		srcs/lst/ft_lstnew.c \
		srcs/print/ft_putchar_fd.c \
		srcs/print/ft_putchar.c \
		srcs/print/ft_putendl_fd.c \
		srcs/print/ft_putendl.c \
		srcs/print/ft_putnbr_fd.c \
		srcs/print/ft_putnbr.c \
		srcs/print/ft_putstr_fd.c \
		srcs/print/ft_putstr.c \
		srcs/string/ft_bzero.c \
		srcs/string/ft_memalloc.c \
		srcs/string/ft_memccpy.c \
		srcs/string/ft_memchr.c \
		srcs/string/ft_memcmp.c \
		srcs/string/ft_memcpy.c \
		srcs/string/ft_memdel.c \
		srcs/string/ft_memmove.c \
		srcs/string/ft_memset.c \
		srcs/string/ft_strcat.c \
		srcs/string/ft_strchr.c \
		srcs/string/ft_strclen.c \
		srcs/string/ft_strclr.c \
		srcs/string/ft_strcmp.c \
		srcs/string/ft_strcpy.c \
		srcs/string/ft_strdel.c \
		srcs/string/ft_strdup.c \
		srcs/string/ft_strequ.c \
		srcs/string/ft_striter.c \
		srcs/string/ft_striteri.c \
		srcs/string/ft_strjoin.c \
		srcs/string/ft_strlcat.c \
		srcs/string/ft_strlen.c \
		srcs/string/ft_strmap.c \
		srcs/string/ft_strmapi.c \
		srcs/string/ft_strncat.c \
		srcs/string/ft_strncmp.c \
		srcs/string/ft_strncpy.c \
		srcs/string/ft_strnequ.c \
		srcs/string/ft_strnew.c \
		srcs/string/ft_strnstr.c \
		srcs/string/ft_strrchr.c \
		srcs/string/ft_strsplit.c \
		srcs/string/ft_strspn.c \
		srcs/string/ft_strstr.c \
		srcs/string/ft_strsub.c \
		srcs/string/ft_strtrim.c \
		srcs/swap/ft_swap_char.c \
		srcs/swap/ft_swap_str.c \
		srcs/swap/ft_swap.c \

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
