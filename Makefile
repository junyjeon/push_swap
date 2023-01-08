# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/01/08 15:00:42 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		=  \
./0_push_swap.c \
./1_stack_init.c \
./2_parsing_stack_and_array.c \
./3_check_duplicate_and_sort.c \
./4_ranked.c \
./5_quick_sort.c \
./6_hard_coding.c \
./command/command.c \
./command/pa_pb.c \
./command/reverse_rotate.c \
./command/rotate.c \
./command/swap.c \
./command/push_pop.c \
./util/ft_atoi_ll.c \
./util/ft_lstadd_back.c \
./util/ft_lstadd_front.c \
./util/ft_lstlast.c \
./util/ft_lstnew.c \
./util/ft_memcpy.c \
./util/ft_split.c \
./util/ft_strdup.c \
./util/ft_strjoin.c \
./util/ft_strlen.c \
./util/ft_strncmp.c \
./util/ft_substr.c
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -I.
CC			=	cc
INC_DIR		=	./includes

.INTERMEDIATE : $(SRCS:.c=.o)
.PHONY : all .c.o clean fclean re bonus

all :		$(NAME)

$(NAME) : mandatory

mandatory :	$(SRCS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean : ; rm -f $(OBJS)

fclean : clean ; rm -f $(NAME)

re:	fclean all
