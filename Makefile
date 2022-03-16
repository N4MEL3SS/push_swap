# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celadia <celadia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 12:57:31 by celadia           #+#    #+#              #
#    Updated: 2022/03/13 19:58:59 by celadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	PROGRAM_NAMES
NAME_PS = push_swap
NAME_CH = checker


#	FLAG_COMPILATION
CC = clang
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIR)


#	HEADERS
HEADERS_LIST =	push_swap.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))


#	SOURCE
SRCS_DIR = ./srcs/
SRCS_LIST = 	command_choice.c	\
	commands.c						\
	commands_stack_a.c				\
	commands_stack_b.c				\
	direction.c						\
	free.c							\
	get_next_line.c					\
	get_next_line_utils.c			\
	index.c							\
	init.c							\
	markup.c						\
	parser.c						\
	print_commands.c				\
	push.c							\
	reverse_rotate.c				\
	rotate.c						\
	stack.c							\
	swap.c							\
	utils.c							\
	validator.c
SRCS_LIST_PS = push_swap.c
SRCS_LIST_CH = checker_bonus.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_PS = $(addprefix $(SRCS_DIR), $(SRCS_LIST_PS))
SRCS_CH = $(addprefix $(SRCS_DIR), $(SRCS_LIST_CH))


#	OBJECT_FILES
OBJS_DIR = ./objs/
OBJS_DIR_NAME = objs
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_LIST_PS = $(patsubst %.c, %.o, $(SRCS_LIST_PS))
OBJS_LIST_CH = $(patsubst %.c, %.o, $(SRCS_LIST_CH))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))
OBJS_PS = $(addprefix $(OBJS_DIR), $(OBJS_LIST_PS))
OBJS_CH = $(addprefix $(OBJS_DIR), $(OBJS_LIST_CH))


#	COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


all: $(NAME_PS)

bonus: $(NAME_CH)

$(NAME_PS): $(OBJS_DIR) $(OBJS) $(OBJS_PS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(OBJS_PS) -o $(NAME_PS)
	@echo "$(GREEN) $(NAME_PS) created. $(RESET)"

$(NAME_CH): $(OBJS_DIR) $(OBJS) $(OBJS_CH)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(OBJS_CH) -o $(NAME_CH)
	@echo "$(GREEN) $(NAME_CH) created. $(RESET)"

$(OBJS_DIR):
	@mkdir  -p $(OBJS_DIR_NAME)
	@echo "$(GREEN) Object files directory was created. $(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_PS)
	@rm -rf $(OBJS_CH)
	@echo "$(RED) Object files were deleted. $(RESET)"

fclean: clean
	@rm -f $(NAME_PS)
	@echo "$(RED) $(NAME_PS) was deleted. $(RESET)"
	@rm -f $(NAME_CH)
	@echo "$(RED) $(NAME_CH) was deleted. $(RESET)"

re: fclean all

re_bonus: fclean bonus

re_all: fclean all bonus

.PHONY: all bonus clean fclean re re_bonus re_all
