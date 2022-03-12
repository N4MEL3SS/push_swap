#include "push_swap.h"

//TODO: Удалить
#include <fcntl.h>

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

void	print_commands_fd(t_cmds_head *cmds_head)
{
	t_cmds_lst		*current;
	char			c;
	int				fd;

	fd = open("/mnt/c/School21/push_swap/commands.txt", O_RDWR);
	current = cmds_head->head;
	while (current)
	{
		while (current->command)
		{
			c = (char)(current->command % 100 + 32);
			current->command /= 100;
			write(fd, &c, 1);
		}
		write(fd, "\n", 1);
		current = current->next;
	}
	close(fd);
}
