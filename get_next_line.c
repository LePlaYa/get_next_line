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

int	get_line_length(char *save)
{
	int	len;

	len = 0;
	while (save[len] != '\n' && save[len] != '\0')
		len++;
	return (len);
}

char	*add_new_line_symbol(char *save)
{
	return (ft_strjoin(save, "\n"));
}

char	*get_new_line(char **save, char **line)
{
	int		len;
	char	*tmp;

	len = get_line_length(*save);
	if ((*save)[len] == '\n')
	{
		*line = ft_substr(*save, 0, len);
		tmp = ft_strdup(&(*save)[len + 1]);
		free(*save);
		*save = tmp;
		if ((*save)[0] == '\0')
		{
			free(*save);
			*save = NULL;
		}
	}
	else
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
	}
	add_new_line_symbol(*line);
	return (*line);
}

char	*output(char **save, char **line, int r)
{
	if (r < 0)
		return (NULL);
	else if (r == 0 && *save == NULL)
		return (NULL);
	else
		return (get_new_line(save, line));
}

char	*get_next_line(int fd)
{
	int				r;
	static char		*save;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;
	char			**line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char *));
	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		if (save == NULL)
			save = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(save, buf);
			if (save != NULL)
				free(save);
			save = tmp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (output(&save, line, r));
}
