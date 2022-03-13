#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack			*stack_gt;
	t_stack			*stack_index;
	t_cmds_head		*commands_gt;
	t_cmds_head		*commands_index;

	if (argc > 1)
	{
		stack_index = parser(--argc, ++argv);
		index_stack(stack_index);
		markup_stack(stack_index, &markup_index);
		commands_index = commands(stack_index, &markup_index);
		free_stack(stack_index);
		stack_gt = parser(argc, argv);
		index_stack(stack_gt);
		markup_stack(stack_gt, &markup_gt);
		commands_gt = commands(stack_gt, &markup_gt);
		free_stack(stack_gt);
		write(1, "index\n", 6);
		print_commands(commands_index);
		write(1, "gt\n", 3);
		print_commands(commands_gt);
//		if (commands_gt->size < commands_index->size)
//			print_commands(commands_gt);
//		else
//			print_commands(commands_index);
		free_command_list(commands_gt);
		free_command_list(commands_index);
	}
	else
		terminate(ERROR_NEED_ARGS, NULL);
	return (0);
}
