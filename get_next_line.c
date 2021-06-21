/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:44:56 by jscheuma          #+#    #+#             */
/*   Updated: 2021/06/08 13:44:56 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int				r;
	static char		*save;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	r = read(fd, buf, BUFFER_SIZE);
	if (save != NULL)
		*line = ft_strdup(save);
	while (r > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			if (ft_strlen(ft_strchr(buf, '\n') + 1) >= 1)
			{
				free(save);
				save = ft_strdup(ft_strchr(buf, '\n') + 1);
			}
			tmp = ft_substr(buf, 0, ft_strlen(buf)
					- ft_strlen(ft_strchr(buf, '\n')));
			*line = ft_strjoin(*line, tmp);
			free(tmp);
			break ;
		}
		else
		{
			if (*line != NULL)
				*line = ft_strjoin(*line, buf);
			else
				*line = ft_strdup(buf);
		}
		r = read(fd, buf, BUFFER_SIZE);
	}
	if (r == 0 && save != NULL)
		free(save);
	return (r);
}
