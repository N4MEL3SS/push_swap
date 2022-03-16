/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:38:01 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:38:01 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_val	*get_next_min(t_stack *stack)
{
	t_stack_val		*min;
	t_stack_val		*current;
	int				size;

	min = NULL;
	current = stack->head;
	size = stack->size + 1;
	while (--size)
	{
		if (!min && (current->index == -1))
			min = current;
		if (min && (current->index == -1) && (current->num < min->num))
			min = current;
		current = current->next;
	}
	return (min);
}

void	index_stack(t_stack *stack_index)
{
	t_stack_val	*current;
	int			index;

	index = -1;
	current = get_next_min(stack_index);
	while (current)
	{
		current->index = ++index;
		current = get_next_min(stack_index);
	}
}

void	index_copy(t_stack *stack_index, t_stack *stack_gt)
{
	t_stack_val		*current_index;
	t_stack_val		*current_gt;
	int				size;

	size = stack_index->size;
	current_index = stack_index->head;
	current_gt = stack_gt->head;
	while (size)
	{
		current_gt->index = current_index->index;
		current_index = current_index->next;
		current_gt = current_gt->next;
		size--;
	}
}
