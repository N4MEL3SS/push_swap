#ifndef STACK_H
# define STACK_H

#define YES 1
#define NO 0

typedef struct s_stack_val
{
	int					num;
	int					index;
	int					save_in_stack_a;
	struct s_stack_val	*prev;
	struct s_stack_val	*next;
}				t_stack_val;

typedef struct s_stack
{
	int				size;
	int				pairs;
	t_stack_val		*head;
	t_stack_val		*marker;
}				t_stack;

/* init.c */
t_stack			*init_stack(void);
t_stack_val		*init_lst(int num, t_stack *stack);

/* stack.c */
void			lst_add(t_stack *stack, t_stack_val *lst);

/* free.c */
void			free_stack(t_stack *stack);

#endif //STACK_H
