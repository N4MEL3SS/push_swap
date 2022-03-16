/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:34:19 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:50:50 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print(t_cmds_head *commands_index, t_cmds_head *commands_gt)
{
	if (commands_gt->size < commands_index->size)
		print_commands(commands_gt);
	else
		print_commands(commands_index);
	free_command_list(commands_gt);
	free_command_list(commands_index);
}

int	main(int argc, char *argv[])
{
	t_stack			*stack_gt;
	t_stack			*stack_index;
	t_cmds_head		*commands_gt;
	t_cmds_head		*commands_index;

	if (argc > 1)
	{
		stack_index = init_stack();
		stack_gt = init_stack();
		parser(--argc, ++argv, stack_index, stack_gt);
		index_stack(stack_index);
		index_copy(stack_index, stack_gt);
		markup_stack(stack_index, &markup_index);
		commands_index = commands(stack_index, &markup_index);
		free_stack(stack_index);
		markup_stack(stack_gt, &markup_gt);
		commands_gt = commands(stack_gt, &markup_gt);
		free_stack(stack_gt);
		print(commands_index, commands_gt);
	}
	return (0);
}
