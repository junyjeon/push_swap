# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/05/20 02:47:08 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror


# Define the directories
GNL_DIR			=	./lib/get_next_line
GNL				=	$(GNL_DIR)/libGNL.a
BUILD_DIR		=	build
INC_DIR			=	-Iincludes -I$(GNL_DIR)
LDFLAGS			=	-L$(GNL_DIR) -lGNL

# Define the source files
ifdef !WITH_BONUS
	SRC_DIR			=	sources
	SRC_MAIN		=	main.c
	SRC_PARSING		=	$(addprefix parsing/, init.c parse.c print_error.c push_pop.c ranked.c)
	SRC_COMMAND		=	$(addprefix command/, push.c reverse_rotate.c rotate.c swap.c)
	SRC_HARDCODING	=	$(addprefix hardcoding/, hard_coding.c sort_three.c sort_four.c sort_five.c)
	SRC_QUICKSORT	=	$(addprefix quicksort/, find_pivot.c partition.c quick_sort.c rotation.c)
	SRC_UTIL		=	$(addprefix util/, ft_atoi_ll.c ft_lstnew.c ft_memcpy.c ft_split.c\
	ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c)
	NAME			=	push_swap
else
	SRC_DIR			=	sources_bonus
	SRC_MAIN		=	checker.c
	SRC_PARSING		=	$(addprefix parsing_bonus/, init_bonus.c parse_bonus.c print_error_bonus.c push_pop_bonus.c ranked_bonus.c)
	SRC_COMMAND		=	$(addprefix command_bonus/, push_bonus.c reverse_rotate_bonus.c rotate_bonus.c swap_bonus.c)
	SRC_HARDCODING	=	$(addprefix hardcoding_bonus/, hard_coding_bonus.c sort_three_bonus.c sort_four_bonus.c sort_five_bonus.c)
	SRC_QUICKSORT	=	$(addprefix quicksort_bonus/, find_pivot_bonus.c partition_bonus.c quick_sort_bonus.c rotation_bonus.c)
	SRC_UTIL		=	$(addprefix util_bonus/, ft_atoi_ll_bonus.c ft_lstnew_bonus.c ft_memcpy_bonus.c ft_split_bonus.c\
	ft_strdup_bonus.c ft_strjoin_bonus.c ft_strlen_bonus.c ft_strncmp_bonus.c ft_strcmp_bonus.c ft_substr_bonus.c)
	SRC_GNL			=	$(addprefix get_next_line_bonus/, get_next_line_bonus.c get_next_line_utils_bonus.c)
	NAME			=	checker
endif

PUSHSWAP_SRCS	=	$(addprefix $(SRC_DIR)/, $(SRC_MAIN) $(SRC_PARSING) $(SRC_COMMAND) $(SRC_HARDCODING) $(SRC_QUICKSORT) $(SRC_UTIL) $(SRC_GNL))
PUSHSWAP_OBJS	=	$(patsubst $(SRC_DIR)/.c, $(BUILD_DIR)/.o, $(PUSHSWAP_SRCS))

all:
	@$(MAKE) -j $(NAME)
	
# Define the target and dependencies
$(NAME): $(PUSHSWAP_OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	@printf "${GREEN}> $(NAME) success 🎉${END}"


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

bonus:
	@make WITH_BONUS=1 all

dir_guard:
	@mkdir -p $(addprefix $(BUILD_DIR)/, parsing)
	@mkdir -p $(addprefix $(BUILD_DIR)/, command)
	@mkdir -p $(addprefix $(BUILD_DIR)/, hardcoding)
	@mkdir -p $(addprefix $(BUILD_DIR)/, quicksort)
	@mkdir -p $(addprefix $(BUILD_DIR)/, util)

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the push_swap have been deleted.❌${END}"

fclean:
	@$(RM) -r $(NAME) $(BUILD_DIR)
	@echo "${YELLOW}> Cleaning of the push_swap has been done.❌${END}"

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)Cleaned and rebuilt everything for push_swap!${END}"

.PHONY:	all clean fclean re dir_guard bonus

#Colors

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

