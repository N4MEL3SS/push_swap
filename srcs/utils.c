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

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}

void	terminate(const char *str, void *address)
{
	free(address);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}
