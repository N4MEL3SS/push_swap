/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:39:32 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 17:48:20 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack, t_stack_val *first, t_stack_val *second)
{
	t_stack_val	*previous;
	t_stack_val	*next;

	previous = first->prev;
	next = second->next;
	previous->next = second;
	second->prev = previous;
	first->next = next;
	next->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void	sa(t_stack *stack_a, t_cmds_head *cmds_head)
{
	swap(stack_a, stack_a->head, stack_a->head->next);
	add_commands(cmds_head, init_cmds_lst(SA));
}

void	sb(t_stack *stack_b, t_cmds_head *cmds_head)
{
	swap(stack_b, stack_b->head, stack_b->head->next);
	add_commands(cmds_head, init_cmds_lst(SB));
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	swap(stack_a, stack_a->head, stack_a->head->next);
	swap(stack_b, stack_b->head, stack_b->head->next);
	add_commands(cmds_head, init_cmds_lst(SS));
}
