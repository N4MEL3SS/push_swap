#include "../includes/push_swap.h"

void	parse_str(t_stack *stack, char *str, int num_count)
{
	long	*num_arr;
	int		i;

	i = -1;
	num_arr = malloc(sizeof(long) * (num_count));
	while (*str)
		str = ft_atoi(str, &num_arr[++i]);
	check_duplicate(num_arr, num_count);
	i = -1;
	while (++i < num_count)
		lst_add(stack, lst_create((int)num_arr[i]));
	free(num_arr);
}

t_stack	*parser(int count, char **value)
{
	t_stack		*stack;
	int			num_count;

	num_count = 0;
	stack = malloc(sizeof(t_stack));
	stack->size = 0;
	stack->pairs = 0;
	stack->head = NULL;
	stack->marker = NULL;
	if (count == 2)
	{
		check_str(*value, &num_count);
		parse_str(stack, *value, num_count);
	}
	return (stack);
}
