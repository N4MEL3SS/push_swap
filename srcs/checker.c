/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:32:47 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 20:05:03 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	stack_check(t_stack *stack_a)
{
	t_stack_val		*current;
	t_stack_val		*current_next;
	int				size;

	size = stack_a->size;
	current = stack_a->head;
	current_next = stack_a->head->next;
	while (--size)
	{
		if (current->num > current_next->num)
			return (1);
		current = current->next;
		current_next = current_next->next;
	}
	return (0);
}

void	stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	char			*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (command_choice(line, stack_a, stack_b))
			terminate(ERROR_INPUT, NULL);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	if (argc > 1)
	{
		stack_a = init_stack();
		stack_b = init_stack();
		if (!stack_a || !stack_b)
			terminate(ERROR_MALLOC, NULL);
		parser_checker(--argc, ++argv, stack_a);
		stack_sort(stack_a, stack_b);
		if (stack_check(stack_a))
			ft_putendl(COLOR_KO);
		else
			ft_putendl(COLOR_OK);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
