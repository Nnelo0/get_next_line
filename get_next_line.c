/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:34:16 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/02 14:46:26 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *stash)
{
	int		len;
	char	*new_line;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(stash);
	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	new_line = malloc(sizeof(char) * ((i - len) + 1));
	if (!new_line)
		return (NULL);
	while (i >= len)
	{
		new_line[j] = stash[len];
		len++;
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static char	*copy_line(char *tmp)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_line(int fd, char *stash)
{
	ssize_t	bytes;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_line(fd, stash);
	line = copy_line(stash);
	stash = next_line(stash);
	return (line);
}

int main()
{
	int fd;
	int i = 0;
	char	*next_line;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	while (i < 17)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		free(next_line);
		i++;
	}
	return(0);
}