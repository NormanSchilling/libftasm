# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 19:25:14 by nschilli          #+#    #+#              #
#    Updated: 2015/02/13 14:33:15 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIB =	ft_isdigit.s \
		ft_isalpha.s \
		ft_isalnum.s \
		ft_isascii.s \
		ft_isprint.s \
		ft_bzero.s \
		ft_toupper.s \
		ft_tolower.s \
		ft_puts.s \
		ft_strcat.s \
		ft_strlen.s \
		ft_memcpy.s \
		ft_memset.s \
		ft_strdup.s \
		ft_cat.s \
		ft_memchr.s \
		ft_strchr.s \
		ft_strncat.s \
		ft_islower.s \
		ft_isupper.s \

NAME		=	libfts.a

CFLAGS		=	-f macho64

OBJ_LIB		=	$(SRC_LIB:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJ_LIB)
	@ar -rc $(NAME) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"Compilation of libfts.a : "\033[32m"Success"\033[0m"


%.o:		%.s
	@echo -n .
	@nasm $(CFLAGS) -s $< -o $@

clean:
	@echo "\033[31m"Objects of libfts.a : deleted"\033[0m"
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@echo "\033[31m"libft.a : deleted"\033[0m"
	@/bin/rm -f $(NAME)

re:			fclean all

test:		re
	@gcc -Wl,-no_pie $(NAME) main.c
	@./a.out

test_1:		re
	@gcc -Wl,-no_pie $(NAME) main.c
	@./a.out test


.PHONY:		all re fclean clean test
