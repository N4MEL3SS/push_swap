/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:39:20 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:39:20 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add(t_stack *stack, t_stack_val *lst)
{
	t_stack_val	*tail;

	if (stack && lst)
	{
		if (!stack->head)
		{
			stack->head = lst;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->prev;
			lst->prev = tail;
			tail->next = lst;
			lst->next = stack->head;
			stack->head->prev = lst;
		}
		stack->size++;
	}
}
