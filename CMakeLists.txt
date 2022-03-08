cmake_minimum_required(VERSION 3.21)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap srcs/push_swap.c includes/push_swap.h includes/stack.h srcs/btree.c srcs/free.c srcs/stack.c srcs/commands.c srcs/parser.c srcs/validator.c srcs/utils.c includes/error_msg.h srcs/index.c)
