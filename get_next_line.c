/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:34:16 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/28 16:27:36 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*copy_line(int fd, char *stash)
{
	char *buf;
	ssize_t test;

	buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	test = 1;
	while (!(ft_strchr(buf, '\n')) || test != 0)
	{
		test = read(fd, stash, BUFFER_SIZE);
		buf = ft_strjoin(buf, stash);
	}
	return (buf);
	
}
#include <stdio.h>
int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	static char *stash = NULL;
	printf("%s", copy_line(fd, stash));
	return (0);
}
/* char	*get_next_line(int fd)
{
	char *buf;
	static const char *stash = NULL;
	
	if (fd == 0 || BUFFER_SIZE == 0)
		return (NULL);
	copy_line(fd, stash);
}

int main()
{
	int fd;
	int i;
	char	*next_line;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	while (i > 5)
	{
		next_line = get_next_line(fd);
		printf("%d", next_line);
		free(next_line);
		return (0);
	}
	return(0);
} */
