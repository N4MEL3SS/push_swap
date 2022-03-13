/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:34:30 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:34:30 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_val	*find_a_elem(t_stack *stack_a, int index)
{
	t_stack_val	*current;

	current = stack_a->marker;
	if (index < current->index)
	{
		while (index < current->prev->index
			&& current->index > current->prev->index)
			current = current->prev;
	}
	else
	{
		while (index > current->index
			&& current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}

void	estimate_direction(t_stack *stack, int index, int *rx_size,
		int *rrx_size)
{
	t_stack_val		*current;

	if (stack && stack->head)
	{
		current = stack->head;
		while (current->index != index && ++(*rx_size))
			current = current->next;
		current = stack->head;
		while (current->index != index && ++(*rrx_size))
			current = current->prev;
	}
}

void	set_direction(size_t size, t_shift shift_info_new, t_shift *shift_info)
{
	if (!shift_info->state || size < shift_info->size)
	{
		shift_info->stack_a_shift = shift_info_new.stack_a_shift;
		shift_info->stack_b_shift = shift_info_new.stack_b_shift;
		shift_info->direction_a = shift_info_new.direction_a;
		shift_info->direction_b = shift_info_new.direction_b;
		shift_info->size = size;
		shift_info->state = TRUE;
	}
}

void	optimal_direct(t_stack *stack_a, t_stack *stack_b,
		t_stack_val *b_val, t_shift *shift_info)
{
	t_shift		shift_info_new;
	int			ra_size;
	int			rra_size;
	int			rb_size;
	int			rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	shift_info_new.stack_a_shift = find_a_elem(stack_a, b_val->index);
	shift_info_new.stack_b_shift = b_val;
	estimate_direction(stack_a, shift_info_new.stack_a_shift->index,
		&ra_size, &rra_size);
	estimate_direction(stack_b, b_val->index,
		&rb_size, &rrb_size);
	shift_info_new.direction_a = ROTATE;
	shift_info_new.direction_b = ROTATE;
	set_direction(ft_max(ra_size, rb_size), shift_info_new, shift_info);
	shift_info_new.direction_a = REVERSE_ROTATE;
	set_direction(rra_size + rb_size, shift_info_new, shift_info);
	shift_info_new.direction_b = REVERSE_ROTATE;
	set_direction(ft_max(rra_size, rrb_size), shift_info_new, shift_info);
	shift_info_new.direction_a = ROTATE;
	set_direction(ra_size + rrb_size, shift_info_new, shift_info);
}

void	direction(t_stack *stack_a, t_stack *stack_b, t_shift *shift_info)
{
	t_stack_val		*current;
	int				i;

	if (stack_b)
	{
		i = -1;
		current = stack_b->head;
		while (++i < stack_b->size)
		{
			optimal_direct(stack_a, stack_b, current, shift_info);
			current = current->next;
		}
	}
}
