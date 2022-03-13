/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:39:13 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:39:13 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	stack->head = stack->head->next;
}

void	ra(t_stack *stack_a, t_cmds_head *cmds_head)
{
	rotate(stack_a);
	add_commands(cmds_head, init_cmds_lst(RA));
}

void	rb(t_stack *stack_b, t_cmds_head *cmds_head)
{
	rotate(stack_b);
	add_commands(cmds_head, init_cmds_lst(RB));
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	rotate(stack_a);
	rotate(stack_b);
	add_commands(cmds_head, init_cmds_lst(RR));
}
