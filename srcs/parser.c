/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:38:25 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:38:25 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*parse_str(char *str, int *size)
{
	long	temp;
	int		*num_arr;
	int		num_count;
	int		i;

	i = -1;
	num_count = check_str(str, NULL);
	num_arr = malloc(sizeof(int) * (num_count));
	if (!num_arr)
		terminate(ERROR_MALLOC, num_arr);
	while (*str)
	{
		str = ft_atoi(str, &temp);
		if (temp < INT32_MIN || temp > INT32_MAX)
			terminate(ERROR_OVERFLOW, num_arr);
		num_arr[++i] = (int)temp;
	}
	check_dups(num_arr, num_count);
	*size = num_count;
	return (num_arr);
}

int	*parse_arr(int count, char **value, int *size)
{
	long	temp;
	int		*num_arr;
	int		i;

	i = -1;
	num_arr = malloc(sizeof(int) * (count));
	if (!num_arr)
		terminate(ERROR_MALLOC, num_arr);
	while (++i < count)
	{
		if (check_str(*value, num_arr) > 1)
			terminate(ERROR_MANY_ARGS, num_arr);
		ft_atoi(*value, &temp);
		if (temp < INT32_MIN || temp > INT32_MAX)
			terminate(ERROR_OVERFLOW, num_arr);
		num_arr[i] = (int)temp;
		value++;
	}
	check_dups(num_arr, count);
	*size = count;
	return (num_arr);
}

t_stack	*parser(int count, char **value)
{
	t_stack		*stack;
	int			*num_arr;
	int			size;
	int			i;

	i = -1;
	if (count == 1)
		num_arr = parse_str(*value, &size);
	else
		num_arr = parse_arr(count, value, &size);
	stack = init_stack();
	while (++i < size)
		lst_add(stack, init_lst((int)num_arr[i], stack));
	free(num_arr);
	return (stack);
}
