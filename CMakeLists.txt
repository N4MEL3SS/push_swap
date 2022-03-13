cmake_minimum_required(VERSION 3.16)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")
add_executable(push_swap srcs/push_swap.c includes/push_swap.h includes/stack.h srcs/free.c srcs/stack.c
		srcs/commands.c srcs/parser.c srcs/validator.c srcs/utils.c includes/error_msg.h srcs/index.c srcs/markup.c
		srcs/commands_stack_a.c srcs/commands_stack_b.c srcs/print_commands.c ../btree/btree.h includes/commands.h
		srcs/init.c srcs/push.c srcs/rotate.c srcs/swap.c srcs/reverse_rotate.c srcs/direction.c)
add_executable(checker srcs/checker.c includes/push_swap.h includes/stack.h srcs/free.c srcs/stack.c
		srcs/commands.c srcs/parser.c srcs/validator.c srcs/utils.c includes/error_msg.h srcs/index.c srcs/markup.c
		srcs/commands_stack_a.c srcs/commands_stack_b.c srcs/print_commands.c ../btree/btree.h includes/commands.h
		srcs/init.c srcs/push.c srcs/rotate.c srcs/swap.c srcs/reverse_rotate.c srcs/direction.c srcs/get_next_line.c
		srcs/get_next_line_utils.c srcs/command_choice.c)
