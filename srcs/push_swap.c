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
	t_btree	*head;
	t_stack	*a;
	t_stack	*a_temp;
	int		i;

	i = -1;
	arr = malloc(sizeof(int) * (argc - 1));
	char_to_int(argv, arr, argc - 1);
	a = stack_init(arr[++i]);
	a_temp = a;
	while (arr[++i])
		a = stack_create(arr[i], a);
	head = btree_create(arr, 1, argc - 1, NULL);
	printf("btree = %d\n", head->value);
	printf("a = %d\n", a_temp->value);
	clean_btree(head);
	free(arr);
	return (0);
}
