/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:44:17 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 19:44:17 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sx(const char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (*line == 'a')
		swap(stack_a, stack_a->head, stack_a->head->next);
	else if (*line == 'b')
		swap(stack_b, stack_b->head, stack_b->head->next);
	else if (*line == 's')
	{
		swap(stack_a, stack_a->head, stack_a->head->next);
		swap(stack_b, stack_b->head, stack_b->head->next);
	}
}

void	push_x(const char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (*line == 'a')
		push(stack_a, pop(stack_b));
	else if (*line == 'b')
		push(stack_b, pop(stack_a));
}

void	rrx(const char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (*line == 'a')
		reverse_rotate(stack_a);
	else if (*line == 'b')
		reverse_rotate(stack_b);
	else if (*line == 'r')
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

void	rx(const char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (*line == 'a')
		rotate(stack_a);
	else if (*line == 'b')
		rotate(stack_b);
	else if (*line == 'r' && ++line)
	{
		if (*line == '\n')
		{
			rotate(stack_a);
			rotate(stack_b);
		}
		else
			rrx(line, stack_a, stack_b);
	}
}

int	command_choice(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (*line == 's')
		sx(++line, stack_a, stack_b);
	else if (*line == 'p')
		push_x(++line, stack_a, stack_b);
	else if (*line == 'r')
		rx(++line, stack_a, stack_b);
	else
		return (1);
	return (0);
}
