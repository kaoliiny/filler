# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 19:37:45 by kaoliiny          #+#    #+#              #
#    Updated: 2019/03/10 21:49:43 by kaoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC	:=			ft_strcmp.c ft_toupper.c ft_strcpy.c	ft_lstadd.c	ft_strdup.c ft_atoi.c	ft_strlen.c	ft_isalnum.c ft_strncat.c ft_isalpha.c ft_strncmp.c	ft_isascii.c ft_strncpy.c	ft_isdigit.c	ft_strnstr.c	ft_isprint.c ft_strrchr.c ft_strcat.c ft_strstr.c ft_strchr.c	ft_tolower.c	ft_memmove.c	ft_memcpy.c	ft_memccpy.c	ft_memcmp.c	ft_memset.c	ft_bzero.c	ft_memchr.c	ft_strlcat.c	ft_putstr_fd.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putendl.c	ft_putnbr_fd.c	ft_putnbr.c	ft_putstr.c	ft_putchar.c	ft_memalloc.c	ft_memdel.c	ft_strnew.c	ft_strdel.c	ft_strclr.c	ft_striter.c	ft_striteri.c	ft_strmap.c	ft_strmapi.c	ft_strequ.c	ft_strnequ.c	ft_strsub.c	ft_strsplit.c	ft_strjoin.c	ft_lstnew.c	ft_lstdelone.c	ft_randint.c	ft_lstiter.c	ft_strtrim.c	ft_lstdel.c	ft_itoa.c	ft_free_array.c	ft_lstmap.c	get_next_line.c	is_num.c

NAME :=			libft.a

OBJ_PATH :=		.obj/
# PRINTF_PATH :=	ft_printf/
# PRINTF_SPATH :=	ft_printf/src/

CC :=			clang
CFLAGS :=		-Wall -Werror -Wextra
IFLAGS :=		-I . #-I $(PRINTF_PATH)includes/

SRCS +=			$(SRC)
# SRCS +=			$(addprefix $(PRINTF_SPATH), $(PRINTFSRCS))
OBJS :=			$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME):		$(OBJ_PATH) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
$(OBJ_PATH)%.o:	%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re