<<<<<<< HEAD
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

=======
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

>>>>>>> ab0ca95f006d1795d9dc2e0519628aa8f8401589
