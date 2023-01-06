# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/01/06 16:53:44 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		= \

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
