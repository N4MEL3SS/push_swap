#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

//TODO: Удалить
#include <stdio.h>

#include "../includes/stack.h"
#include "../includes/error_msg.h"

#define ERROR 1
#define OK 0

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

/* btree.c */
t_btree	*btree_init(int num, int index);
t_btree	*btree_create(int *arr, int index, int size, t_btree *parent);

/* free.c */
void	clean_btree(t_btree *btree);

/* validator.c */
int		check_str(char *str, long *num_arr);
void	check_dup_and_over(long *num_arr, int size);

/* parser.c */
t_stack	*parser(int count, char **value);

void	index_stack(t_stack *stack);

/* utils.c */
char	*ft_atoi(char *str, long *num);
void	terminate(const char *str, void *address);

#endif //PUSH_SWAP_H
