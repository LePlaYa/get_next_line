/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:36:04 by jscheuma          #+#    #+#             */
/*   Updated: 2021/06/08 15:36:04 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	char	*dest;
	char	*d;
	size_t	len;

	s = (char *)str;
	len = ft_strlen(str);
	dest = malloc((len + 1) * sizeof(char));
	d = dest;
	if (dest == NULL)
		return (NULL);
	while (*s)
	{
		*dest = *s;
		dest++;
		s++;
	}
	*dest = '\0';
	return (d);
}

char	*ft_strchr(const char *str, int c)
{
	char	*p;

	p = (char *)str;
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (*p == c)
		return (p);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*out_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = -1;
	out_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!out_str)
		return (NULL);
	while (s1[i])
	{
		out_str[i] = s1[i];
		i++;
	}
	while (s2[++j])
		out_str[i++] = s2[j];
	out_str[i] = '\0';
	return (out_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (ft_strlen(s) < start)
	{
		dest = malloc(sizeof(char));
		if (dest == NULL)
			return (NULL);
		*dest = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
