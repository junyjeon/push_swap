# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 12:20:01 by marvin            #+#    #+#              #
#    Updated: 2022/10/29 12:20:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap.a
SRC			=	push_swap.c
OBJ			=	$(SRC:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	crs

.PHONY : all .c.o clean fclean re

all :		$(NAME)

$(NAME) : mandatory

mandatory : $(NAME)($(OBJ))
clean : ; rm -f $(OBJ)
fclean : clean ; rm -f $(NAME)
re:	fclean all

