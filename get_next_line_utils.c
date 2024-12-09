/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:10:09 by alermi            #+#    #+#             */
/*   Updated: 2024/12/04 14:06:20 by alermi           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char    *ft_free(char *data)
{
    if (data)
        free(data);
    return (NULL);    
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char )c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	char	*p;

	p = (char *)s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	if (dsize == 0)
		return (src_size);
	i = 0;
	while (i < (dsize - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	i;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	i = 0;
	if (dsize <= dst_size)
		return (src_size + dsize);
	while (src[i] && i < dsize - dst_size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst [dst_size + i] = '\0';
	return (src_size + dst_size);
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
		tmp[i++] = 0;
	return (tmp);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	length;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && *s2)
		return (ft_strdup(s2));
	if (!s2 && *s1)
		return (ft_strdup(s1));
	length = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dest = ft_calloc(sizeof(char), length);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, length);
	ft_strlcat(dest, s2, length);
	return (dest);
}
