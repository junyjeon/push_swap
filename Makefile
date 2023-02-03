# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/02/03 21:42:08 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -O3 -g

# Define the directories
MANDATORY_DIR	=	mandatory
CHECKER_DIR		=	checker

SRC_DIR			=	sources
BUILD_DIR		=	build
INC_DIR			=	-I includes

CORE_DIR		=	core
COMMAND_DIR 	=	command
UTILS_DIR 		=	util

# Define the source files
SRCS_CORE		=	$(addprefix $(CORE_DIR)/, check_duplicate_and_sort.c hard_coding.c \
parsing_stack_and_array.c print_error.c push_pop.c quick_sort.c ranked.c stack_init.c)
SRCS_COMMAND	=	$(addprefix $(COMMAND_DIR)/, push.c reverse_rotate.c rotate.c swap.c)
SRCS_UTIL		=	$(addprefix $(UTILS_DIR)/, ft_atoi_ll.c ft_lstnew.c ft_memcpy.c ft_split.c \
ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c)

PUSHSWAP		=	push_swap

PUSHSWAP_SRCS	=	$(addprefix $(SRC_DIR)/, main.c $(SRCS_CORE) $(SRCS_COMMAND) $(SRCS_UTIL))
PUSHSWAP_OBJS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(PUSHSWAP_SRCS))
PUSHSWAP_DEPS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(PUSHSWAP_SRCS))

CHECKER			=	checker

CHECKER_SRCS	=	$(addprefix $(SRC_DIR)/, checker.c $(SRCS_CORE) $(SRCS_COMMAND) $(SRCS_UTIL))
CHECKER_OBJS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(CHECKER_SRCS))
CHECKER_DEPS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(CHECKER_SRCS))

all:
	@$(MAKE) -j $(PUSHSWAP)
bonus: all
	@$(MAKE) -j $(CHECKER)

# Define the target and dependencies

$(PUSHSWAP): $(PUSHSWAP_OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${GREEN}> success 🎉${END}"

$(CHECKER): $(CHECKER_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${GREEN}> success 🎉${END}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c || dir_guard
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
	@printf "											what is?\r"

dir_guard:
	@mkdir -p $(addprefix $BUILD_DIR)/, main.c)
	@mkdir -p $(addprefix $BUILD_DIR)/, $(CORE_DIR))
	@mkdir -p $(addprefix $BUILD_DIR)/, $(COMMAND_DIR))
	@mkdir -p $(addprefix $BUILD_DIR)/, $(UTILS_DIR))

clean:
	@$(RM) $(OBJS) $(DEPS)
	@rm -rf $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the push_swap have been deleted ❌${END}"

fclean:
	@$(RM) $(OBJS) $(DEPS) $(LIBS) $(LIBMLX) push_swap push_swap_bonus
	@rm -rf $(BUILD_DIR)
	@echo "${YELLOW}> Cleaning of the push_swap has been don./e ❌${END}"

re: fclean
	@make all

.PHONY:	all clean fclean re

# minimal color codes
END				=	$'\x1b[0m
BOLD			=	$'\x1b[1m
UNDER			=	$'\x1b[4m
REV				=	$'\x1b[7m
GREY			=	$'\x1b[30m
RED				=	$'\x1b[31m
GREEN			=	$'\x1b[32m
YELLOW			=	$'\x1b[33m
BLUE			=	$'\x1b[34m
PURPLE			=	$'\x1b[35m
CYAN			=	$'\x1b[36m
WHITE			=	$'\x1b[37m

-include $(DEPS)
