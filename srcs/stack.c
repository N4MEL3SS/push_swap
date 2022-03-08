#include "../includes/push_swap.h"

t_stack	*stack_create(void)
{
	t_stack		*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		terminate(ERROR_MALLOC, stack);
	stack->size = 0;
	stack->pairs = 0;
	stack->head = NULL;
	stack->marker = NULL;
	return (stack);
}

t_stack_val	*lst_create(int num, t_stack *stack)
{
	t_stack_val		*lst;

	lst = malloc(sizeof(t_stack_val));
	if (!lst)
	{
		free_stack(stack);
		terminate(ERROR_MALLOC, lst);
	}
	lst->num = num;
	lst->index = -1;
	lst->save_stack = NO;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

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
