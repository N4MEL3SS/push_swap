/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:33:53 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 19:42:10 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdint.h>

# include "stack.h"
# include "shift.h"
# include "commands.h"
# include "error_msg.h"

# define TRUE 1
# define FALSE 0

/* validator.c */
int		check_str(char *str, int *num_arr);
void	check_dups(int *num_arr, int size);

/* parser.c */
void	parser(int count, char **value, t_stack *index, t_stack *gt);

/* index.c */
void	index_stack(t_stack *stack);
void	index_copy(t_stack *stack_index, t_stack *stack_gt);

/* markup.c */
void	markup_stack(t_stack *stack, int (*markup)(t_stack_val *));
int		markup_index(t_stack_val *markup_head);
int		markup_gt(t_stack_val *markup_head);

/* push.c */
void	push(t_stack *stack, t_stack_val *val);
void	pa(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head);
void	pb(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head);

/* rotate.c */
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a, t_cmds_head *cmds_head);
void	rb(t_stack *stack_b, t_cmds_head *cmds_head);
void	rr(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head);

/* reverse_rotate.c */
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a, t_cmds_head *cmds_head);
void	rrb(t_stack *stack_b, t_cmds_head *cmds_head);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head);

/* swap.c */
void	swap(t_stack *stack, t_stack_val *first, t_stack_val *second);
void	sa(t_stack *stack_a, t_cmds_head *cmds_head);
void	sb(t_stack *stack_b, t_cmds_head *cmds_head);

void	ss(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head);

/* direction.c */
void	direction(t_stack *stack_a, t_stack *stack_b, t_shift *shift_info);

/* print_commands.c */
void	print_commands(t_cmds_head *cmds_head);

/* free.c */
void	free_command_list(t_cmds_head *cmds_head);

/* utils.c */
int		ft_max(int a, int b);
void	ft_putendl(const char *str);
char	*ft_atoi(char *str, long *num);
void	terminate(const char *str, void *address);

#endif //PUSH_SWAP_H
