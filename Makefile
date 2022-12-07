# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2022/12/07 21:54:05 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap.a
SRC			=	\
0_push_swap.c \
1_init.c \
2_push_pop.c \
3_swap_ss.c \
4_push_pa_pb.c \
5_rotate_rr_rrr.c \
6_error.c \
7_little_sort.c \
8_merge_sort.c \
util.c \

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

