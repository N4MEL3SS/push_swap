#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

//TODO: Удалить
#include <stdio.h>

#include "../includes/stack.h"
#include "../includes/error_msg.h"
#include "../includes/commands.h"

#include "../includes/btree.h"

#define TRUE 1
#define FALSE 0

/* validator.c */
int		check_str(char *str, long *num_arr);
void	check_dup_and_over(long *num_arr, int size);

/* parser.c */
t_stack	*parser(int count, char **value);

/* index.c */
void	index_stack(t_stack *stack);

/* markup.c */
void	markup_stack(t_stack *stack, int (*markup)(t_stack_val *));
int		markup_index(t_stack_val *markup_head);
int		markup_gt(t_stack_val *markup_head);

/* utils.c */
char	*ft_atoi(char *str, long *num);
void	terminate(const char *str, void *address);

void	swap(t_stack *stack_a, t_stack_val *head);

t_stack_val	*pop(t_stack *stack);
void	push(t_stack *stack, t_stack_val *val);

void	rotate(t_stack *stack);

#endif //PUSH_SWAP_H
