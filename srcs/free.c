/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:37:54 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:37:54 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack_val		*current;
	t_stack_val		*delete;
	int				i;

	i = -1;
	current = stack->head;
	while (++i < stack->size)
	{
		delete = current;
		current = current->next;
		free(delete);
	}
	free(stack);
}

void	free_command_list(t_cmds_head *cmds_head)
{
	t_cmds_lst	*current;
	t_cmds_lst	*delete;

	current = cmds_head->head;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete);
	}
	free(cmds_head);
}
