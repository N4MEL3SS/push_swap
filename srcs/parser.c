#include "../includes/push_swap.h"


long	*parse_str(char *str, int *size)
{
	long	*num_arr;
	int		num_count;
	int		i;

	i = -1;
	num_count = check_str(str, NULL);
	num_arr = malloc(sizeof(long) * (num_count));
	while (*str)
		str = ft_atoi(str, &num_arr[++i]);
	check_dup_and_over(num_arr, num_count);
	*size = num_count;
	return (num_arr);
}

long	*parse_arr(int count, char **value, int *size)
{
	long	*num_arr;
	int		i;

	i = -1;
	num_arr = malloc(sizeof(long) * (count));
	while (++i < count)
	{
		if (check_str(*value, num_arr) > 1)
			terminate(ERROR_MANY, num_arr);
		ft_atoi(*value, &num_arr[i]);
		value++;
	}
	check_dup_and_over(num_arr, count);
	*size = count;
	return (num_arr);
}

t_stack	*parser(int count, char **value)
{
	t_stack		*stack;
	long		*num_arr;
	int			size;
	int			i;

	i = -1;
	if (count == 1)
		num_arr = parse_str(*value, &size);
	else
		num_arr = parse_arr(count, value, &size);
	stack = stack_create();
	while (++i < size)
		lst_add(stack, lst_create((int)num_arr[i], stack));
	free(num_arr);
	return (stack);
}
