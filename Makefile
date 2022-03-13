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

NAME_PS = push_swap
NAME_CH = checker

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
	utils.c
SRCS_LIST_PS = push_swap.c
SRCS_LIST_CH = checker.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_PS = $(addprefix $(SRCS_DIR), $(SRCS_LIST_PS))
SRCS_CH = $(addprefix $(SRCS_DIR), $(SRCS_LIST_CH))

OBJS_DIR = ./objs/
OBJS_DIR_NAME = objs
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_LIST_PS = $(patsubst %.c, %.o, $(SRCS_LIST_PS))
OBJS_LIST_CH = $(patsubst %.c, %.o, $(SRCS_LIST_CH))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))
OBJS_PS = $(addprefix $(OBJS_DIR), $(OBJS_LIST_PS))
OBJS_CH = $(addprefix $(OBJS_DIR), $(OBJS_LIST_CH))

all: $(NAME_PS)

bonus: $(NAME_CH)

$(NAME_PS): $(OBJS_DIR) $(OBJS) $(OBJS_PS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(OBJS_PS) -o $(NAME_PS)
	@echo "$(NAME_PS) created."

$(NAME_CH): $(OBJS_DIR) $(OBJS) $(OBJS_CH)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(OBJS_PS) -o $(NAME_CH)
	@echo "$(NAME_CH) created."

$(OBJS_DIR):
	@mkdir  -p $(OBJS_DIR_NAME)
	@echo "Object files directory was created."

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_PS)
	@rm -rf $(OBJS_CH)
	@echo "Object files were deleted."

fclean: clean
	@rm -f $(NAME_PS)
	@echo "$(NAME_PS) was deleted."
	@rm -f $(NAME_CH)
	@echo "$(NAME_CH) was deleted."

re: fclean all

re_bonus: fclean all bonus

.PHONY: all bonus clean fclean re
