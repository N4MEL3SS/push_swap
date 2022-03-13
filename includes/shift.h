/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:34:35 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 13:47:53 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIFT_H
# define SHIFT_H

# include "stack.h"
# include "push_swap.h"

# define ROTATE 1
# define REVERSE_ROTATE 2

typedef struct s_shift
{
	t_stack_val		*stack_a_shift;
	t_stack_val		*stack_b_shift;
	int				direction_a;
	int				direction_b;
	int				size;
	int				state;
}				t_shift;

/* init.c */
t_shift	*init_shift_info(void);

#endif //SHIFT_H
