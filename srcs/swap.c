/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:39:32 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:39:32 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack_a, t_stack_val *head)
{
	t_stack_val		*prev;
	t_stack_val		*next;

	prev = head->prev;
	next = head->next;
	prev->next = next;
	next->prev = prev;
	head->prev = next;
	head->next = next->next;
	next->next = head;
	stack_a->head = next;
}

void	sa(t_stack *stack_a, t_cmds_head *cmds_head)
{
	swap(stack_a, stack_a->head);
	add_commands(cmds_head, init_cmds_lst(SA));
}

void	sb(t_stack *stack_b, t_cmds_head *cmds_head)
{
	swap(stack_b, stack_b->head);
	add_commands(cmds_head, init_cmds_lst(SB));
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	sa(stack_a, cmds_head);
	sb(stack_b, cmds_head);
	add_commands(cmds_head, init_cmds_lst(SS));
}
