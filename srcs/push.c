/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:38:50 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:38:50 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, t_stack_val *val)
{
	t_stack_val		*tail;

	if (!stack->head)
	{
		stack->head = val;
		stack->head->prev = stack->head;
		stack->head->next = stack->head;
	}
	else
	{
		tail = stack->head->prev;
		val->prev = tail;
		tail->next = val;
		val->next = stack->head;
		stack->head->prev = val;
		stack->head = val;
	}
	stack->size++;
}

t_stack_val	*pop(t_stack *stack)
{
	t_stack_val	*val;

	val = NULL;
	if (stack->size == 1)
	{
		val = stack->head;
		stack->head = NULL;
		val->prev = NULL;
		val->next = NULL;
	}
	else
	{
		val = stack->head;
		stack->head = stack->head->next;
		val->prev->next = val->next;
		val->next->prev = val->prev;
		val->prev = NULL;
		val->next = NULL;
	}
	stack->size--;
	return (val);
}

void	pa(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	push(stack_a, pop(stack_b));
	add_commands(cmds_head, init_cmds_lst(PA));
}

void	pb(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	push(stack_b, pop(stack_a));
	add_commands(cmds_head, init_cmds_lst(PB));
}
