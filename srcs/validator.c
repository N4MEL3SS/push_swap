#include "../includes/push_swap.h"

void	check_str(char *str, int *num_count)
{
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (48 <= *str && *str <= 57 && ++*num_count)
			while (48 <= *str && *str <= 57)
				str++;
		else
			terminate(ERROR_INPUT);
	}
}

void	check_duplicate(long *num_arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (num_arr[i] == num_arr[j])
			{
				free(num_arr);
				terminate(ERROR_DUPLICATE);
			}
		}
	}
}
