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

#include "../includes/push_swap.h"

void	lst_add(t_stack *stack, t_stack_val *lst)
{
	if (stack && lst)
	{
		t_stack_val		*tail;
		t_stack_val		*head;

		if (!stack->head)
		{
			stack->head = lst;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			head = stack->head;
			tail = head->prev;
			lst->next = head;
			lst->prev = tail;
			head->prev = lst;
			tail->next = lst;
		}
		stack->size++;
	}
}
