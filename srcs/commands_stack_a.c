/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:37:29 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 17:37:45 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	needs_push(t_stack *stack_a)
{
	t_stack_val		*current;
	int				i;

	i = -1;
	current = stack_a->head;
	while (++i < stack_a->size)
	{
		if (!current->save_in_stack_a)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}

int	needs_swap(t_stack *stack_a, int (*markup)(t_stack_val *))
{
	int		pairs;

	if (stack_a && stack_a->size >= 2)
	{
		swap(stack_a, stack_a->head, stack_a->head->next);
		pairs = markup(stack_a->marker);
		swap(stack_a, stack_a->head, stack_a->head->next);
		markup(stack_a->marker);
		if (pairs > stack_a->pairs)
			return (TRUE);
	}
	return (FALSE);
}

void	commands_a(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head,
		int (*markup)(t_stack_val *))
{
	while (needs_push(stack_a))
	{
		if (needs_swap(stack_a, markup))
		{
			sa(stack_a, cmds_head);
			stack_a->pairs = markup(stack_a->marker);
		}
		else if (stack_a->head->save_in_stack_a == NO)
			pb(stack_a, stack_b, cmds_head);
		else
			ra(stack_a, cmds_head);
	}
}
