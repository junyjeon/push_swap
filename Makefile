# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/01/04 13:14:18 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		= \
0_push_swap.c \
10_checker.c \
1_init.c \
6_error_check.c \
7_little_sort.c \
8_make_array.c \
9_merge_sort.c \
command_pa_pb.c \
command_push_pop.c \
command_reverse_rotate.c \
command_rotate.c \
command_swap.c \
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
CFLAGS		=	-Wall -Wextra -Werror -I. -g
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
