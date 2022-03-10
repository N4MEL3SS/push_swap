#include "../includes/push_swap.h"

int	needs_push_b(t_stack *stack_a)
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

int	needs_swap_a(t_stack *stack_a, int (*markup)(t_stack_val *))
{
	int		pairs;

	swap(stack_a, stack_a->head);
	pairs = markup(stack_a->marker);
	swap(stack_a, stack_a->head);
	markup(stack_a->marker);
	if (pairs > stack_a->pairs)
		return (TRUE);
	return (FALSE);
}

void	commands_a(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head,
		int (*markup)(t_stack_val *))
{
	while (needs_push_b(stack_a))
	{
		if (needs_swap_a(stack_a, markup))
		{
			swap(stack_a, stack_a->head);
			add_commands(cmds_head, init_cmds_lst(SA));
			stack_a->pairs = markup(stack_a->marker);
		}
		else if (stack_a->head->save_in_stack_a == NO)
		{
			push(stack_b, pop(stack_a));
			add_commands(cmds_head, init_cmds_lst(PB));
		}
		else
		{
			rotate(stack_a);
			add_commands(cmds_head, init_cmds_lst(RA));
		}
	}
}
