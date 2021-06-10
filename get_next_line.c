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

	if (fd < 0 || line == NULL)
		return (-1);
	r = read(fd, buf, BUFFER_SIZE);
	if (r < 0)
	{
		return (r);
	}
	while (r > 0)
	{
		tmp = ft_strchr(buf, '\n');
		if (tmp)
		{
			if (ft_strlen(tmp) > 1)
				save = ft_strdup(tmp + 1);
			*line = ft_strjoin(*line, );
			break ;
		}
		else
		{

		}
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (r);
}
