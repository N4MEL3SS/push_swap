/*
 * Old code. Just save
 */

//#include "../includes/push_swap.h"
//
//void	parse_str(t_stack *stack, int num_count, char *str)
//{
//	long	*num_arr;
//	int		i;
//
//	i = -1;
//	num_arr = malloc(sizeof(long) * (num_count));
//	while (*str)
//		str = ft_atoi(str, &num_arr[++i]);
//	check_dup_and_over(num_arr, num_count, stack);
//	i = -1;
//	while (++i < num_count)
//		lst_add(stack, lst_create((int)num_arr[i]));
//	free(num_arr);
//}
//
//void	parse_arr(t_stack *stack, int count, char **value)
//{
//	int		i;
//	int		num_count;
//	long	*num_arr;
//
//	i = -1;
//	num_count = 0;
//	num_arr = malloc(sizeof(long) * (count));
//	while (++i < count)
//	{
//		check_str(*value, &num_count, stack);
//		if (num_count > 1)
//			terminate(ERROR_MANY, NULL, stack);
//		ft_atoi(*value, &num_arr[i]);
//		value++;
//	}
//}
//
//t_stack	*parser(int count, char **value)
//{
//	t_stack		*stack;
//	int			num_count;
//
//	num_count = 0;
//	stack = stack_create();
//	if (count == 2 && !check_str(*value, &num_count, stack))
//		parse_str(stack, num_count, *value);
//	else
//		parse_arr(stack, count, value);
//	return (stack);
//}
