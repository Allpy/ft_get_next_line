/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:52:09 by alermi            #+#    #+#             */
/*   Updated: 2024/12/09 19:11:04 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int	fd;

	fd = open("alo", O_CREAT | O_RDWR , 0777);
	write(fd, "alp\n", 4);
	write(fd, "eren\n", 5);
	write(fd, "lermi\n", 6);
	close(fd);
	fd = open("alo", O_CREAT | O_RDWR, 0777);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
