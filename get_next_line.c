/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:34:16 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:46 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *copy_line(char *tmp)
{
	char	*fin;
	int		len;
	int i;
	
	len = 0;
	i = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0')
		len++;
	fin = malloc(sizeof(char *) * (len + 1));
	if (!fin)
		return (NULL);
	while (i <= len)
	{
		fin[i] = tmp[i];
		i++;
	}
	return (fin);
}
static char	*get_line(int fd)
{
	ssize_t bytes;
	char buf[BUFFER_SIZE + 1];
	char *tmp;

	bytes = 1;
	tmp = malloc(sizeof(char *) + (ft_strlen(buf)));
	if (!tmp)
		return (NULL);
	while (bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(tmp, '\n'))
		{
			return (tmp);
			break;
		}
	}
	return (tmp);
}
char	*get_next_line(int fd)
{
	char *line;
	line = get_line(fd);
	line = copy_line(line);
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
	while (i < 1)
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
	char *buf = malloc(sizeof(char *) + (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	char *tmp = malloc(sizeof(char *) + (ft_strlen(buf) + 1)); */
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

