/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:05:52 by celadia           #+#    #+#             */
/*   Updated: 2021/12/07 17:05:52 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_read_file(int fd, char *stat_str)
{
	char		*line_str;
	ssize_t		line_len;
	ssize_t		stat_len;
	ssize_t		full_len;

	line_str = malloc(sizeof(char) * 1);
	*line_str = '\0';
	full_len = 0;
	if (!ft_str_chr(stat_str, &line_len))
	{
		stat_len = 1;
		while (stat_len > 0 && !ft_str_chr(stat_str, &line_len))
		{
			full_len += line_len;
			line_str = ft_str_join(line_str, stat_str, full_len);
			stat_len = read(fd, stat_str, BUFFER_SIZE);
			if (!line_str || stat_len == -1)
				return (NULL);
			*(stat_str + stat_len) = '\0';
		}
	}
	line_str = ft_str_join(line_str, stat_str, full_len + line_len);
	ft_str_cpy(stat_str, line_len);
	return (line_str);
}

char	*get_next_line(int fd)
{
	static char		*stat_str;
	char			*line_str;
	char			check;

	if (fd < 0 || read(fd, &check, 0) == -1)
		return (NULL);
	if (!stat_str)
	{
		stat_str = malloc(sizeof(char) * ((ssize_t)BUFFER_SIZE + 1));
		if (!stat_str)
			return (NULL);
		*stat_str = '\0';
	}
	line_str = get_read_file(fd, stat_str);
	if (line_str == NULL || *line_str == '\0')
	{
		stat_str = ft_free_ptr(stat_str);
		line_str = ft_free_ptr(line_str);
	}
	return (line_str);
}
