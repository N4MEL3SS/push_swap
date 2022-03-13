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
	int				temp;
	char			c;

	current = cmds_head->head;
	while (current)
	{
		temp = current->command;
		while (temp)
		{
			c = (char)(temp % 100 + 32);
			temp /= 100;
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		current = current->next;
	}
}
