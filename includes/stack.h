#ifndef STACK_H
# define STACK_H

#include <stdlib.h>

typedef struct	s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

t_stack	*stack_init(int num);
t_stack	*stack_create(int num, t_stack *prev);

#endif //STACK_H
