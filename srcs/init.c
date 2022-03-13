/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:38:08 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:38:08 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack		*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		terminate(ERROR_MALLOC, stack);
	stack->size = 0;
	stack->pairs = 0;
	stack->head = NULL;
	stack->marker = NULL;
	return (stack);
}

t_stack_val	*init_lst(int num, t_stack *stack)
{
	t_stack_val		*lst;

	lst = malloc(sizeof(t_stack_val));
	if (!lst)
	{
		free_stack(stack);
		terminate(ERROR_MALLOC, lst);
	}
	lst->num = num;
	lst->index = -1;
	lst->save_in_stack_a = NO;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

t_cmds_head	*init_cmds(void)
{
	t_cmds_head		*cmds;

	cmds = malloc(sizeof(t_cmds_head));
	if (!cmds)
		terminate(ERROR_MALLOC, cmds);
	cmds->size = 0;
	cmds->head = NULL;
	cmds->tail = NULL;
	return (cmds);
}

t_cmds_lst	*init_cmds_lst(int cmds_name)
{
	t_cmds_lst		*lst;

	lst = malloc(sizeof(t_cmds_lst));
	if (!lst)
		terminate(ERROR_MALLOC, lst);
	lst->command = cmds_name;
	lst->next = NULL;
	return (lst);
}

t_shift	*init_shift_info(void)
{
	t_shift		*shift_info;

	shift_info = malloc(sizeof(t_shift));
	if (!shift_info)
		terminate(ERROR_MALLOC, shift_info);
	shift_info->stack_a_shift = NULL;
	shift_info->stack_b_shift = NULL;
	shift_info->direction_a = ROTATE;
	shift_info->direction_b = REVERSE_ROTATE;
	shift_info->size = 0;
	shift_info->state = FALSE;
	return (shift_info);
}
