#include "../includes/push_swap.h"

t_btree	*btree_init(int num, int index)
{
	t_btree	*head;

	head = malloc(sizeof(t_btree));
	head->value = num;
	head->index = index + 1;
	head->parent = NULL;
	head->left = NULL;
	head->right = NULL;
	return (head);
}

t_btree	*btree_create(int *arr, int index, int size, t_btree *parent)
{
	t_btree		*child;

	if (index <= size)
	{
		child = malloc(sizeof(t_btree));
		child->value = arr[index - 1];
		child->index = index;
		child->parent = parent;
		child->left = NULL;
		child->right = NULL;
		if (parent && index % 2 == 0)
			parent->left = child;
		else if (parent && index % 2 == 1)
			parent->right = child;
		btree_create(arr, index * 2, size, child); //Проход по левой ветке
		btree_create(arr, index * 2 + 1, size, child); //Проход по правой ветке
	}
	if (index == 1)
		return (child);
	return (NULL);
}
