# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celadia <celadia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 12:57:31 by celadia           #+#    #+#              #
#    Updated: 2022/03/13 14:43:57 by celadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

CC = clang
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIR)

HEADERS_LIST =	push_swap.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRCS_DIR = ./srcs/
SRCS_LIST = 	init.c	\
	stack.c				\
	parser.c			\
	validator.c			\
	index.c				\
	markup.c			\
	commands.c			\
	commands_stack_a.c	\
	commands_stack_b.c	\
	direction.c			\
	rotate.c			\
	reverse_rotate.c	\
	swap.c				\
	push.c				\
	free.c				\
	print_commands.c	\
	push_swap.c			\
	utils.c
SRCS_LIST_PS = push_swap.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_PS = $(addprefix $(SRCS_DIR), $(SRCS_LIST_PS))

OBJS_DIR = objs/
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_LIST_PS = $(patsubst %.c, %.o, $(SRCS_LIST_PS))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))
OBJS_PS = $(addprefix $(OBJS_DIR), $(OBJS_LIST_PS))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_PS)

$(NAME_PS): $(OBJS) $(OBJS_PS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(OBJS_PS) -o $(NAME_PS)
	@echo "$(NAME_PS) created."

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "Object files directory was created."

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "Object files were deleted."

fclean:
	@rm -f $(NAME_PS)
	@echo "$(NAME_PS) was deleted."

re: fclean all

.PHONY: all clean fclean re
