#include "push_swap.h"

int	check_str(char *str, long *num_arr)
{
	int		num_count;

	num_count = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (48 <= *str && *str <= 57 && ++num_count)
			while (48 <= *str && *str <= 57)
				str++;
		else
			terminate(ERROR_INPUT, num_arr);
	}
	return (num_count);
}

void	check_dup_and_over(long *num_arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		if (num_arr[i] < INT32_MIN || num_arr[i] > INT32_MAX)
			terminate(ERROR_OVERFLOW, num_arr);
		j = i;
		while (++j < size)
			if (num_arr[i] == num_arr[j])
				terminate(ERROR_DUPLICATE, num_arr);
	}
}
