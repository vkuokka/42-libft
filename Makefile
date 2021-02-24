# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 11:41:03 by vkuokka           #+#    #+#              #
#    Updated: 2021/02/24 15:16:43 by vkuokka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = libft.a
src = src/arrays/ft_arrfree.c \
	src/arrays/ft_arriter.c \
	src/ctypes/ft_isalnum.c \
	src/ctypes/ft_isalpha.c \
	src/ctypes/ft_isascii.c \
	src/ctypes/ft_iscntrl.c \
	src/ctypes/ft_isdigit.c \
	src/ctypes/ft_isgraph.c \
	src/ctypes/ft_islower.c \
	src/ctypes/ft_isprint.c \
	src/ctypes/ft_ispunct.c \
	src/ctypes/ft_isspace.c \
	src/ctypes/ft_isspace.c \
	src/ctypes/ft_isupper.c \
	src/ctypes/ft_tolower.c \
	src/ctypes/ft_toupper.c \
	src/dlst/ft_ddel.c \
	src/dlst/ft_dlstadd.c \
	src/dlst/ft_dlstaddback.c \
	src/dlst/ft_dlstdel.c \
	src/dlst/ft_dlstdelone.c \
	src/dlst/ft_dlstiter.c \
	src/dlst/ft_dlstlen.c \
	src/dlst/ft_dlstmap.c \
	src/dlst/ft_dlstnew.c \
	src/numbers/ft_atoi.c \
	src/numbers/ft_count_digits_only.c \
	src/numbers/ft_count_digits.c \
	src/numbers/ft_ftoa.c \
	src/numbers/ft_itoa_base.c \
	src/numbers/ft_itoa.c \
	src/lst/ft_del.c \
	src/lst/ft_lstadd.c \
	src/lst/ft_lstaddback.c \
	src/lst/ft_lstdel.c \
	src/lst/ft_lstdelone.c \
	src/lst/ft_lstiter.c \
	src/lst/ft_lstlen.c \
	src/lst/ft_lstmap.c \
	src/lst/ft_lstnew.c \
	src/memory/ft_bzero.c \
	src/memory/ft_memalloc.c \
	src/memory/ft_memccpy.c \
	src/memory/ft_memchr.c \
	src/memory/ft_memcmp.c \
	src/memory/ft_memcpy.c \
	src/memory/ft_memdel.c \
	src/memory/ft_memmove.c \
	src/memory/ft_memset.c \
	src/memory/ft_realloc.c \
	src/print/ft_putchar_fd.c \
	src/print/ft_print_bits.c \
	src/print/ft_putchar.c \
	src/print/ft_putendl_fd.c \
	src/print/ft_putendl.c \
	src/print/ft_putnbr_fd.c \
	src/print/ft_putnbr.c \
	src/print/ft_putstr_fd.c \
	src/print/ft_putstr.c \
	src/printf/ft_dprintf.c \
	src/printf/ft_printf.c \
	src/printf/parse.c \
	src/printf/parse_c.c \
	src/printf/parse_s.c \
	src/printf/parse_p.c \
	src/printf/parse_di.c \
	src/printf/parse_o.c \
	src/printf/parse_u.c \
	src/printf/parse_lower_x.c \
	src/printf/parse_upper_x.c \
	src/printf/parse_f.c \
	src/printf/putprint.c \
	src/strings/ft_lfind.c \
	src/strings/ft_strcat.c \
	src/strings/ft_strchr.c \
	src/strings/ft_strclen.c \
	src/strings/ft_strclr.c \
	src/strings/ft_strcmp.c \
	src/strings/ft_strcpy.c \
	src/strings/ft_strdel.c \
	src/strings/ft_strdup.c \
	src/strings/ft_strequ.c \
	src/strings/ft_striter.c \
	src/strings/ft_striteri.c \
	src/strings/ft_strjoin.c \
	src/strings/ft_strlcat.c \
	src/strings/ft_strlen.c \
	src/strings/ft_strmap.c \
	src/strings/ft_strmapi.c \
	src/strings/ft_strncat.c \
	src/strings/ft_strncmp.c \
	src/strings/ft_strncpy.c \
	src/strings/ft_strnequ.c \
	src/strings/ft_strnew.c \
	src/strings/ft_strnstr.c \
	src/strings/ft_strrchr.c \
	src/strings/ft_strreplace.c \
	src/strings/ft_strsplit.c \
	src/strings/ft_strspn.c \
	src/strings/ft_strstr.c \
	src/strings/ft_strsub.c \
	src/strings/ft_strtrim.c \
	src/swap/ft_swap_char.c \
	src/swap/ft_swap_str.c \
	src/swap/ft_swap.c \
	src/get_next_line.c
obj = $(notdir $(src:.c=.o))
inc = inc/
flags = -Wall -Werror -Wextra

all:
	@echo "Creating $(name) ..."
	@gcc $(flags) -I $(inc) -c $(src)
	@ar rc $(name) $(obj)
	@ranlib $(name)
	@echo Success!

clean:
	@echo "Removing $(name) object files ..."
	@rm -f $(obj)

fclean: clean
	@echo "Removing $(name) ..."
	@rm -f $(name)

re: fclean all
