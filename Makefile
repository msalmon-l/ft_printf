# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 20:46:03 by msalmon-          #+#    #+#              #
#    Updated: 2022/05/09 19:58:11 by msalmon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

#OBLIGATORY PART

SRCS	= ft_itoa.c ft_bzero.c ft_calloc.c ft_c_hex.c ft_itoa_unsigned.c ft_printf.c ft_putstr.c ft_strlen.c ft_putchar.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all: 		${NAME}

#OTHER 

clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	clean fclean re all
