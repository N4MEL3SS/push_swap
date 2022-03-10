#ifndef COMMANDS_H
# define COMMANDS_H

#define SA 10
#define SB 11
#define SS 12
#define PA 20
#define PB 21
#define RA 30
#define RB 31
#define RR 32
#define RRA 40
#define RRB 41
#define RRR 42

typedef struct s_cmds_lst
{
	int						command;
	struct s_cmds_lst		*next;
}				t_cmds_lst;

typedef struct s_cmds_head
{
	int						size;
	struct s_cmds_lst		*head;
	struct s_cmds_lst		*tail;
}				t_cmds_head;

/* init.c */
t_cmds_head		*init_cmds(void);
t_cmds_lst		*init_cmds_lst(int cmds_name);

/* commands.c */
void			add_commands(t_cmds_head *cmds_head, t_cmds_lst *lst);
t_cmds_head		*cmds(t_stack *stack_a, int (*markup)(t_stack_val *));

void			commands_a(t_stack *stack_a, t_stack *stack_b,
					t_cmds_head *cmds_head, int (*markup)(t_stack_val *));
#endif //COMMANDS_H
