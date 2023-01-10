/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:23:10 by Verdant           #+#    #+#             */
/*   Updated: 2023/01/10 14:52:40 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*read_file(char *buffer, int fd)
// {
// 	int			bytes_read;
// 	char		buff_read[BUFFER_SIZE + 1];
	
// 	bytes_read = -1;
// 	while (bytes_read != 0 && !search_char(buffer, '\n'))
// 	{
// 		bytes_read = read(fd, buff_read, BUFFER_SIZE);
// 		if (bytes_read == -1)
// 			return (NULL);
// 		buff_read[bytes_read] = '\0';
// 		if (bytes_read != 0)
// 			buffer = join_buffers(buffer, buff_read);
// 	}
// 	return (buffer);
// }



char	*modify(char buffer[], char *line)
{
	const int	size = ft_strclen(line, '\n') + 1;
	const int	total = strlen(line) - size;
	int				i;
	char			*return_line;
	static int d = 0;

	i = 0;
	return_line = malloc(sizeof(char) * ft_strclen(line, '\n') + 2);
	if (!return_line)
		return (NULL);
	while (i < size && line[i])
	{
		return_line[i] = line[i];
		i++;
	}
	return_line[i] = '\0';
	i = 0;
	while (i < total && line[size + i])
	{
		buffer[i] = line[size + i];
		i++;
	}
	buffer[i] = '\0';
	d++;
	if (d == 1)
		free(line);
	return (return_line);
}

char	*join_buffers(char *buf1, char *buf2)
{
	const int	length = strlen(buf1) + strlen(buf2);
	char			*new;
	int				i = 0;
	int				k = 0;
	
	new = NULL;
	new = malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	while (i < length && buf1[i])
	{
		new[i] = buf1[i];
		i++;
	}
	new[length] = '\0';
	while(i < length && buf2[k])
		new[i++] = buf2[k++]; // Not sure about this
	new[i] = '\0';
	return (new);
}

char	*read_file(char *buffer, int fd)
{
	int			bytes_read;
	char		buff_read[BUFFER_SIZE + 1];
	
	bytes_read = -1;
	while (!search_char(buffer, '\n'))
	{
		bytes_read = read(fd, buff_read, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buff_read[bytes_read] = '\0';
			buffer = join_buffers(buffer, buff_read);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char				*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	line = read_file(buffer, fd);
	if (line[0] == '\0' && buffer[0] == '\0')
		return (NULL);
	line = modify(buffer, line);
	return (line);
}

// int main(int argc, char *argv[])
// {
// 	if (argc == 0)
// 		return (EXIT_FAILURE);
// 	int		fd = open(argv[1],O_RDONLY);
// 	char	*line;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	system("leaks -q a.out");
// }