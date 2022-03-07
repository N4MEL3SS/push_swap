#include "../includes/push_swap.h"
#include "../includes/stack.h"
#include <stdio.h>

void	char_to_int(char **argv, int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		arr[i] = atoi(&argv[i + 1][0]);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	t_btree	*btree_root;
	t_stack	*a_tail;
	t_stack	*a_head;
	t_stack *a_temp;
	int		i;

	i = -1;

	//	Создание входного массива чисел
	arr = malloc(sizeof(int) * argc);
	char_to_int(argv, arr, argc - 1);

	//	Инициализация и создание стека
	a_tail = stack_init(arr[++i]);
	a_temp = a_tail;
	while (++i < argc - 1)
	{
		a_head = stack_create(arr[i], a_temp);
		a_temp = a_temp->next;
	}
	a_head->next = a_tail;
	a_tail->prev = a_head;

	//	Создание дерева
	btree_root = btree_create(arr, 1, argc - 1, NULL);

	printf("btree_root = %d\n", btree_root->value);
	printf("a_tail = %d\n", a_head->next->value);
	printf("a_head = %d\n", a_head->value);

	//	Освобождение памяти
	clean_btree(btree_root);
	clean_stack(a_head);
	free(arr);
	return (0);
}
