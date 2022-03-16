/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:38:32 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:38:32 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_commands(t_cmds_head *cmds_head)
{
	t_cmds_lst		*current;
	char			c[4];
	int				temp;
	int				i;

	c[3] = '\0';
	current = cmds_head->head;
	while (current)
	{
		i = -1;
		temp = current->command;
		while (++i < 3)
		{
			c[i] = '\0';
			if (temp)
				c[i] = (char)(temp % 100 + 32);
			temp /= 100;
		}
		ft_putendl(c);
		current = current->next;
	}
}
