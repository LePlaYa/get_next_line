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

char	*dest_count(char *d, size_t n)
{
	while (n != 0 && *d)
	{
		d++;
		n--;
	}
	return (d);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	char	*d;
	char	*s;
	size_t	d_len;
	size_t	n;

	d = dest;
	s = (char *)src;
	n = dest_size;
	d = dest_count(d, n);
	d_len = d - dest;
	n = dest_size - d_len;
	if (n == 0)
		return (d_len + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d = *s;
			n--;
			d++;
		}
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_size;

	src_size = 0;
	if (dest_size == 0)
	{
		while (src[src_size])
		{
			src_size++;
		}
		return (src_size);
	}
	while (src_size < dest_size - 1 && src[src_size] != '\0')
	{
		dest[src_size] = src[src_size];
		src_size++;
	}
	if (src_size < dest_size)
		dest[src_size] = '\0';
	while (src[src_size] != '\0')
		src_size++;
	return (src_size);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(dest, s1, len);
	ft_strlcat(dest, s2, len);
	free(s1);
	s1 = dest;
	return (dest);
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
