/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:34:52 by celadia           #+#    #+#             */
/*   Updated: 2022/03/13 12:34:52 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# include <unistd.h>
# include "push_swap.h"

# define ERROR_DUPLICATE	"ERROR: Found duplicates"
# define ERROR_MALLOC		"ERROR: Failed to allocate memory"
# define ERROR_OVERFLOW		"ERROR: Overflow detected"
# define ERROR_INPUT		"ERROR: Incorrect input data"
# define ERROR_MANY_ARGS	"ERROR: Many arguments in line"
# define ERROR_NEED_ARGS	"ERROR: Not enough arguments"

#endif //ERROR_MSG_H
