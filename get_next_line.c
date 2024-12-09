/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:10:32 by alermi            #+#    #+#             */
/*   Updated: 2024/12/09 19:10:05 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	*ft_get_line(int fd, char *data)
{
    ssize_t	byte_size; // readd dönüş değeri ssize_t
    char    *buffer;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (buffer == NULL)
		return (ft_free(data));
	while (1)
	{
		byte_size = read(fd, buffer, BUFFER_SIZE);
		if (byte_size < 0)
			return (free(buffer), data = NULL, NULL);
		if (byte_size == 0)
			break ;
		buffer[byte_size] = '\0';
		data = ft_strjoin(data, buffer);
		if (!data)
			return (free(data), free(buffer), data = NULL, buffer = NULL, NULL);
		if (ft_strchr(data, '\n'))
			break ;
	}
	free (buffer);
	return (data);
}

static char	*ft_str_creator(char *data)
{
	int		i;
	char	*str;

	i = -1;
	while (data[++i] != '\n' && data[i] != '\0')
		;
	if (data[i] == '\n')
		i++;
	str =	(char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (free(data), data = NULL, NULL);
	i = -1;
	while (data[++i] != '\n' && data[i] != '\0')
		str[i] = data[i];
	if (data[i] == '\n')
		str[i] = '\n';
	return (str);
}

static char *ft_data_update(char *data)
{
	char *updated_data;
	size_t	i;
	size_t	j;

	i = -1;
	while (data[++i] != '\n' && data[i] != '\0')
		;
	if (data[++i] == '\n')
		i++;
	updated_data = (char *)ft_calloc(i + 1 ,sizeof(char));
	if (!updated_data)
		return (free(data), data = NULL, NULL);
	j = 0;
	while (data[i])
		updated_data[j++] = data[i++];
	return (free(data), updated_data);
}

char    *get_next_line(int fd)
{
    static char *data;
    char    *str;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (0);
    data = ft_get_line(fd, data);
	if (!data)
		return (ft_free(data), data = NULL, NULL);
	str = ft_str_creator(data);
	if (!str)
		return ( free(data), data = NULL, NULL);
	data = ft_data_update(data);
	return (str);
}
