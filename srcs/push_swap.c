#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_cmds_head		*cmds_head;
	t_stack			*stack_index;

	if (argc > 1)
	{
		stack_index = parser(--argc, ++argv);
		index_stack(stack_index);
		markup_stack(stack_index, &markup_index);
		cmds_head = cmds(stack_index, &markup_index);
		free_stack(stack_index);
	}
	else
		terminate(ERROR_NEED_ARGS, NULL);
	return (0);
}
