/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:10:32 by alermi            #+#    #+#             */
/*   Updated: 2024/12/04 14:04:55 by alermi           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char    *ft_get_line(int fd, char *data)
{
    long    byte_size;
    char    *buffer;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (ft_free(data));
}

char    *get_next_line(int fd)
{
    static char *data;
    char    *str;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (0);
    data = read_line;
}
