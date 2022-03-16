/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:39:39 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:39:39 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_atoi(char *str, long *num)
{
	short int		sign;
	long			result;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' && ++str)
		sign = -1;
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10L + (long)*str - 48L;
		str++;
	}
	if (result > 9223372036854775807 && sign == 1)
		*num = -1;
	if (result > 9223372036854775807 && sign == -1)
		*num = 0;
	*num = result * sign;
	return (str);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}

void	ft_putendl(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	terminate(const char *str, void *address)
{
	free(address);
	ft_putendl(str);
	exit(1);
}
