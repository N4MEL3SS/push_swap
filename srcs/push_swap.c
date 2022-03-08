#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_index;

	if (argc > 1)
	{
		stack_index = parser(--argc, ++argv);
		free_stack(stack_index);
	}
	return (0);
}
