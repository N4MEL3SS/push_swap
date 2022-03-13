/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:39:32 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 16:33:16 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack_val *head)
{
	int		temp_num;
	int		temp_index;
	int		temp_save;

	temp_num = head->num;
	temp_index = head->index;
	temp_save = head->save_in_stack_a;
	head->num = head->next->num;
	head->index = head->next->index;
	head->save_in_stack_a = head->next->save_in_stack_a;
	head->next->num = temp_num;
	head->next->index = temp_index;
	head->next->save_in_stack_a = temp_save;
}

void	sa(t_stack *stack_a, t_cmds_head *cmds_head)
{
	swap(stack_a->head);
	add_commands(cmds_head, init_cmds_lst(SA));
}

void	sb(t_stack *stack_b, t_cmds_head *cmds_head)
{
	swap(stack_b->head);
	add_commands(cmds_head, init_cmds_lst(SB));
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	sa(stack_a, cmds_head);
	sb(stack_b, cmds_head);
	add_commands(cmds_head, init_cmds_lst(SS));
}
