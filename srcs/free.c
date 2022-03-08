#include "../includes/push_swap.h"

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
	t_stack_val		*current;
	t_stack_val		*delete;
	size_t			i;

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
