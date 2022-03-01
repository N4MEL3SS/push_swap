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

//void	free_stack()
//{
//};
