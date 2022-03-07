#ifndef STACK_H
# define STACK_H

#define YES 1
#define NO 0

typedef struct		s_stack_val
{
	int					num;
	int					index;
	int					save_stack;
	struct s_stack_val	*prev;
	struct s_stack_val	*next;
}					t_stack_val;

typedef struct	s_stack
{
	size_t			size;
	size_t			pairs;
	t_stack_val		*head;
	t_stack_val		*marker;
}				t_stack;

t_stack_val		*lst_create(int num);
void			lst_add(t_stack *stack, t_stack_val *lst);

#endif //STACK_H
