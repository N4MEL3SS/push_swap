#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

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

#endif //PUSH_SWAP_H
