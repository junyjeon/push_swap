# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2022/10/25 07:01:30 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap.a
SRC			=	
BONUS_SRC	=	
OBJ			=	$(SRC:.c=.o)
BONUS_OBJ	= 	$(BONUS_SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	crs

.PHONY : all .c.o clean fclean re bonus

all :		$(NAME)

$(NAME) : mandatory

mandatory : $(NAME)($(OBJ))
bonus : $(NAME)($(OBJ) $(BONUS_OBJ))
clean : ; rm -f $(OBJ) $(BONUS_OBJ) 
fclean : clean ; rm -f $(NAME)
re:	fclean all

