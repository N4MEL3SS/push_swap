/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:38:16 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:40:14 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	markup_index(t_stack_val *markup_head)
{
	t_stack_val		*current;
	int				index;
	int				pairs;

	pairs = 0;
	index = markup_head->index;
	markup_head->save_in_stack_a = YES;
	current = markup_head->next;
	while (current != markup_head)
	{
		if (current->index == index + 1)
		{
			index++;
			pairs++;
			current->save_in_stack_a = YES;
		}
		else
			current->save_in_stack_a = NO;
		current = current->next;
	}
	return (pairs);
}

int	markup_gt(t_stack_val *markup_head)
{
	t_stack_val		*current;
	int				index;
	int				pairs;

	pairs = 0;
	index = markup_head->index;
	markup_head->save_in_stack_a = YES;
	current = markup_head->next;
	while (current != markup_head)
	{
		if (current->index > index)
		{
			pairs++;
			index = current->index;
			current->save_in_stack_a = YES;
		}
		else
			current->save_in_stack_a = NO;
		current = current->next;
	}
	return (pairs);
}

void	markup_stack(t_stack *stack, int (*markup)(t_stack_val *))
{
	t_stack_val		*current;
	int				current_pairs;
	int				i;

	i = -1;
	current = stack->head;
	while (++i < stack->size)
	{
		current_pairs = markup(current);
		if (current_pairs > stack->pairs)
		{
			stack->marker = current;
			stack->pairs = current_pairs;
		}
		else if (current_pairs == stack->pairs
			&& (!stack->marker || current->num < stack->marker->num))
			stack->marker = current;
		current = current->next;
	}
	markup(stack->marker);
}
