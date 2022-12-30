# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2022/12/29 22:14:49 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		= \
0_push_swap.c \
10_checker.c \
1_init.c \
2_push_pop.c \
3_swap_ss.c \
4_push_pa_pb.c \
5_rotate_rr_rrr.c \
6_error.c \
7_little_sort.c \
8_make_array.c \
9_merge_sort.c \
util/ft_atoi_ll.c \
util/ft_lstadd_back.c \
util/ft_lstadd_front.c \
util/ft_lstlast.c \
util/ft_lstnew.c \
util/ft_memcpy.c \
util/ft_split.c \
util/ft_strdup.c \
util/ft_strjoin.c \
util/ft_strlen.c \
util/ft_strncmp.c \
util/ft_substr.c
BONUS_SRC	=	
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJ	= 	$(BONUS_SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -I.
CC			=	cc
INC_DIR		=	./includes

.INTERMEDIATE : $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)
.PHONY : all .c.o clean fclean re bonus

all :		$(NAME)

$(NAME) : mandatory

mandatory :	$(SRCS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME)
#	cp ./push_swap ./$(NAME)
	
bonus : $(SRCS:.c=.o) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean : ; rm -f $(OBJS) $(BONUS_OBJ) 

fclean : clean ; rm -f $(NAME)

re:	fclean all

# $(SRCS:.c=.o) 소스 파일의 .c부분을 .o로 치환
