#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_index;

	if (argc > 1)
	{
		stack_index = parser(--argc, ++argv);
		index_stack(stack_index);
		free_stack(stack_index);
	}
	else
		terminate(ERROR_FEW_ARGS, NULL);
	return (0);
}
