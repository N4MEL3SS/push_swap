/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:37:35 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:40:14 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_rotate_twin(t_stack *stack_a, t_stack *stack_b,
		t_shift *shift_info, t_cmds_head *cmds_head)
{
	if (shift_info->direction_a == ROTATE)
		rr(stack_a, stack_b, cmds_head);
	else
		rrr(stack_a, stack_b, cmds_head);
}

void	move_b_rotate_a(t_stack *stack_a, t_stack *stack_b, t_shift *shift_info,
		t_cmds_head *cmds_head)
{
	if (shift_info->direction_a == ROTATE)
		ra(stack_a, cmds_head);
	else
		rra(stack_a, cmds_head);
}

void	move_b_rotate_b(t_stack *stack_a, t_stack *stack_b, t_shift *shift_info,
		t_cmds_head *cmds_head)
{
	if (shift_info->direction_b == ROTATE)
		rb(stack_b, cmds_head);
	else
		rrb(stack_b, cmds_head);
}

void	move_b(t_stack *stack_a, t_stack *stack_b, t_shift *shift_info,
			t_cmds_head *cmds_head)
{
	while (shift_info->stack_a_shift != stack_a->head
		|| shift_info->stack_b_shift != stack_b->head)
	{
		if (shift_info->direction_a == shift_info->direction_b
			&& shift_info->stack_a_shift != stack_a->head
			&& shift_info->stack_b_shift != stack_b->head)
			move_b_rotate_twin(stack_a, stack_b, shift_info, cmds_head);
		else if (shift_info->stack_a_shift != stack_a->head)
			move_b_rotate_a(stack_a, stack_b, shift_info, cmds_head);
		else if (shift_info->stack_b_shift != stack_b->head)
			move_b_rotate_b(stack_a, stack_b, shift_info, cmds_head);
	}
}

void	commands_b(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	t_shift		*shift_info;

	shift_info = init_shift_info();
	while (stack_b->size)
	{
		shift_info->state = FALSE;
		direction(stack_a, stack_b, shift_info);
		move_b(stack_a, stack_b, shift_info, cmds_head);
		pa(stack_a, stack_b, cmds_head);
	}
	free(shift_info);
}
