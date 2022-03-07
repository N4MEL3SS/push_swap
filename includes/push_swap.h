#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

#include "../includes/stack.h"

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

typedef struct	s_btree
{
	int				value;
	int				index;
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;

t_btree	*btree_init(int num, int index);
t_btree	*btree_create(int *arr, int index, int size, t_btree *parent);

void	clean_btree(t_btree *btree);
void	clean_stack(t_stack *stack);

#endif //PUSH_SWAP_H
