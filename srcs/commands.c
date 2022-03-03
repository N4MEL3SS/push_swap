#include "../includes/stack.h"
#include "../includes/push_swap.h"

void	commands_sa(t_stack *stack_tail)
{
	int		buff;

	buff = stack_tail->prev->value;
	stack_tail->prev->value = stack_tail->value;
	stack_tail->value = buff;
}

void	commands_choise(t_stack *stack_head, t_stack *stack_tail,
			int command)
{
	if (command == SA)
		commands_sa(stack_tail);
	if (command == SB)
		;
	if (command == PA)
		;
	if (command == PB)
		;
	if (command == RA)
		;
	if (command == RB)
		;
	if (command == RRA)
		;
	if (command == RRB)
		;
}
