/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:35:17 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 18:42:47 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# define SA 6583
# define SB 6683
# define SS 8383
# define PA 6580
# define PB 6680
# define RA 6582
# define RB 6682
# define RR 8282
# define RRA 658282
# define RRB 668282
# define RRR 828282

typedef struct s_cmds_lst
{
	int						command;
	struct s_cmds_lst		*next;
}				t_cmds_lst;

typedef struct s_cmds_head
{
	int				size;
	t_cmds_lst		*head;
	t_cmds_lst		*tail;
}				t_cmds_head;

/* init.c */
t_cmds_head		*init_cmds(void);
t_cmds_lst		*init_cmds_lst(int cmds_name);

/* commands.c */
void			add_commands(t_cmds_head *cmds_head, t_cmds_lst *lst);
t_cmds_head		*commands(t_stack *stack_a, int (*markup)(t_stack_val *));

/* commands_stack_a.c */
void			commands_a(t_stack *stack_a, t_stack *stack_b,
					t_cmds_head *cmds_head, int (*markup)(t_stack_val *));

/* commands_stack_b.c */
void			commands_b(t_stack *stack_a, t_stack *stack_b,
					t_cmds_head *cmds_head);

#endif //COMMANDS_H
