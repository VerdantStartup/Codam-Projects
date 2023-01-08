/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdant <Verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:23:10 by Verdant           #+#    #+#             */
/*   Updated: 2023/01/08 23:31:45 by Verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 100
#endif


size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s != 0)
	{
		i++;
		s++;
	}
	return (i);
}

void	leaks(void)
{
	system("leaks -q a.out");
}

int	search_char(char *buffer, char c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
		return (dest);
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
// By adding size to the function I can save the join buffer function because I add the new 
// read bytes at to correct index




// void	trim_buffer(char *buffer, char *line)
// {
// 	const int size = ft_strclen(line, '\n') + 1;
// 	int	i;

// 	i = 0;
// 	ft_memmove(buffer, buffer + size, strlen(buffer) - size + 1);
// }

char	*join_buffers(char *buf1, char *buf2)
{
	const int	length = strlen(buf1) + strlen(buf2);
	char			*new;
	int				i = 0;
	int				k = 0;
	
	new = malloc(sizeof(char) * (length + 1)); // Do I overwrite any memory here?
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
	new[length] = '\0';
	return (new);
}


// I think I need to add this for if I call the function again and there is nothing to reed

char	*read_file(char *buffer, int fd)
{
	int			bytes_read;
	char		buff_read[BUFFER_SIZE + 1];
	
	bytes_read = 0;
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






void	modify(char buffer[], char *line)
{
	int size = ft_strclen(line, '\n') + 1;
	int i = 0;
	if (!search_char(line, '\n'))
		return ;
	while (i < BUFFER_SIZE && line[size])
	{
		buffer[i] = line[size];
		i++;
		size++;
	}
	buffer[i] = '\0';
}

// This is kinda the same as substr // I could use sub str instead of these two lines
char	*return_one_line(char *line)
{
	int	size;

	size = (ft_strclen(line, '\n') + 1);
	line[size] = '\0';
	return (line);
}

// Is this buffer static though? In other words if I call it again will it remember what I've read?

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char				*line;

	buffer[BUFFER_SIZE] = '\0';
	line = read_file(buffer, fd);
	if (!line)
		return (NULL);
	modify(buffer, line);
	
	line = return_one_line(line);
	return (line);
}


// Everything seems to work other than detecting that the end of file has been reached
// I will have to do testing

int main(int argc, char *argv[])
{
	int		fd = open(argv[1],O_RDONLY);
	char	*line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	// atexit(leaks);
}