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

#include "../includes/push_swap.h"
#include <stdio.h>

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
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*line;

	stack_a = parser(--argc, ++argv);
	if (!stack_a)
		terminate(ERROR_MALLOC, NULL);
	stack_b = init_stack();
	line = get_next_line(0);
	while (line != NULL)
	{
		if (command_choice(line, stack_a, stack_b))
			terminate(ERROR_INPUT, NULL);
		line = get_next_line(0);
	}
	if (stack_check(stack_a))
		write(1, "KO", 2);
	else
		write(1, "OK", 2);
	write(1, "\n", 1);
	free_stack(stack_a);
	free_stack(stack_b);
	free(line);
	return (0);
}
