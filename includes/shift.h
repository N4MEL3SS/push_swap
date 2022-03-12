#ifndef PUSH_SWAP_SHIFT_H
# define PUSH_SWAP_SHIFT_H

#include "stack.h"

#define ROTATE 1
#define REVERSE_ROTATE 2

typedef struct s_shift
{
	t_stack_val		*stack_a_shift;
	t_stack_val		*stack_b_shift;
	int				direction_a;
	int				direction_b;
	int				size;
	int				state;
}				t_shift;

t_shift	*init_shift_info(void);

#endif //PUSH_SWAP_SHIFT_H
