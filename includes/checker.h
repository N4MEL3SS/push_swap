/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:26:47 by celadia           #+#    #+#             */
/*   Updated: 2022/03/16 10:27:03 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "stack.h"
# include "error_msg.h"
# include "get_next_line.h"

# define COLOR_OK "\e[32mOK\e[39m"
# define COLOR_KO "\e[31mKO\e[39m"

/* validator.c */
int		check_str(char *str, int *num_arr);
void	check_dups(int *num_arr, int size);

/* parser.c */
void	parser_checker(int count, char **value, t_stack *stack);

/* command_choice.c */
int		command_choice(char *line, t_stack *stack_a, t_stack *stack_b);

/* utils.c */
void	ft_putendl(const char *str);
void	terminate(const char *str, void *address);

#endif //CHECKER_H
