/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:40:09 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:40:09 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_str(char *str, int *num_arr)
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

void	check_dups(int *num_arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (num_arr[i] == num_arr[j])
				terminate(ERROR_DUPLICATE, num_arr);
	}
}
