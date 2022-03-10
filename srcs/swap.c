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
