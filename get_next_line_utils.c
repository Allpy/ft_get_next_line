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
