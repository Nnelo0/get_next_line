/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:34:16 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/31 17:37:05 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *next_line(char *stash)
{
	int len;
	char *new_line;
	int i;
	int j;
	
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
static char *copy_line(char *tmp)
{
	char	*line;
	int		len;
	int i;
	
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
	ssize_t bytes;
	char buf[BUFFER_SIZE + 1];
	char *tmp;
	
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break;
		buf[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			break;
	}
	return (stash);
}
char	*get_next_line(int fd)
{
	char *line;
	static char	*stash = NULL;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//printf("stash debut = %s\n", stash);
	stash = get_line(fd, stash);
	//printf("stash apres GL = %s\n", stash);
	line = copy_line(stash);
	//printf("stash apres L = %s\n", stash);
	stash = next_line(stash);
	//printf("stash apres NL = %s\n", stash);
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
	while (i < 10)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		free(next_line);
		i++;
	}
	return(0);
}
/* int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	get_next_line(fd); */
/* 	ssize_t bytes = 1;
	char *buf = malloc(sizeof(char) + (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	char *tmp = malloc(sizeof(char) + (ft_strlen(buf) + 1)); */
//	int i = 0;
//	int j = 0;
	/* bytes = read(fd, buf, BUFFER_SIZE);
	printf("\nbuf = %s", buf);
 	while (buf[j] != '\0')
	{
		tmp[i] = buf[j];
		i++;
		j++;
	}
	tmp = ft_strjoin(tmp, buf);
	if (ft_strchr(tmp, '\n'))
		printf("y'a un truc");
	printf("\ntmp = %s",tmp);
	bytes = read(fd, buf, BUFFER_SIZE);
	j = 0;
 	while (buf[j] != '\0')
	{
		tmp[i] = buf[j];
		i++;
		j++;
	} 
	tmp = ft_strjoin(tmp, buf);
	if (ft_strchr(tmp, '\n'))
		printf("y'a un truc2");
		
	printf("\ntmp = %s",tmp);
	printf("\nbuf = %s", buf); */
/* 	while (bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(tmp, '\n'))
		{
			return (tmp);
			break;
		}
	}
	printf("tmp = %s", tmp); */

/* static char	*testget_line(int fd, char *stash)
{
	ssize_t bytes;
	char *buf;
	char *tmp;
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = 1;
	tmp = malloc(sizeof(char) * (ft_strlen(stash) + 1));
	if (!tmp)
		return (NULL); 
	tmp = ft_strjoin(stash,"");
	printf("stash avnt malloc = %s\n", stash);
	stash = malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (!stash)
		return (NULL);
	stash = ft_strjoin(tmp, "");
	printf("stash apres malloc = %s\n", stash);
	while (bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n'))
			break;
	}
	return (stash);
} */