#include "../includes/push_swap.h"
#include "../includes/stack.h"

void	free_btree(t_btree *btree)
{
	if (btree->parent)
	{
		if (btree->parent->right == btree)
			btree->parent->right = NULL;
		else
			btree->parent->left = NULL;
	}
	free(btree);
	btree = NULL;
}

void	clean_btree(t_btree *btree)
{
	while (btree->right || btree->left)
	{
		if (btree->right)
			clean_btree(btree->right);
		else
			clean_btree(btree->left);
	}
	free_btree(btree);
}

void	free_stack(t_stack *stack)
{
	free(stack);
	stack = NULL;
};

void	clean_stack(t_stack *stack)
{
	t_stack		*delete;
	t_stack		*stack_tail;

	stack_tail = stack->next;
	while (stack != stack_tail)
	{
		delete = stack;
		stack->prev->next = stack->next;
		stack = stack->prev;
		free_stack(delete);
	}
	free_stack(stack);
}
