	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   get_next_line.c                                    :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2022/10/27 14:56:22 by verdant           #+#    #+#             */
	/*   Updated: 2022/11/13 03:32:06 by verdant          ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "get_next_line.h"
	#include <stdbool.h>
	#include <stdio.h>
	#include <fcntl.h>
	#include <string.h>

	static char	*trim_buf(char *buf, char *current_line)
	{
		int		cur_len;
		char	*next_line;
		int	new_len;
		// int		i;

		// i = 0;
		if (!current_line)
			return (NULL);
		cur_len = ft_strclen(current_line, false);
		// next_line = malloc((BUFFER_SIZE + 1) * sizeof(char)); // Sumthing wrong here with counting or just use calloc
		// if (!next_line)
		// 	return (free(buf), NULL);
		// while (buf[cur_len + i])
		// {
		// 	next_line[i] = buf[cur_len + i];
		// 	i++;
		// }
		// next_line[i] = '\0';
		new_len = ft_strclen(buf, false) - cur_len;
		next_line = ft_substr(buf, cur_len, new_len);
		free(buf);
		return (next_line);
	}

	static char	*ft_current_line(char *buf)
	{
		char	*current_line;
		int		line_len;

		if (!buf)
			return (NULL);
		if (!(*buf))
		{
			buf[0] = '\0';
			return (free(buf), NULL);
		}
		line_len = ft_strclen(buf, true);
		if (line_len || buf[0] == '\n')
			current_line = ft_substr(buf, 0, 1 + line_len);
		else
			current_line = ft_substr(buf, 0, ft_strclen(buf, false));
		return (current_line);
	}

	static char	*join_buffers(char *s1, char *s2, int *size, int s2_len)
	{
		const int	s1_len = ft_strclen(s1, false);
		char		*target;
		int			i;

		i = 0;
		if (s1_len + s2_len < *size - 1 && s2[0] != '\n' && s1[i])
			return (ft_concat(s1, s2, s1_len));
		*size *= 2;
		target = malloc((*size) * sizeof(char)); // Sumthing wrong here with counting or just use calloc
		if (!target )
		{
			printf("3");
			return (NULL);
		}
		while (s1[i] && i < s1_len)
		{
			target[i] = s1[i];
			i++;
		}
		free(s1);
		ft_concat(target, s2, s1_len);
		return (target);
	}

	static char	*ft_read(char *static_buf, int fd)
	{
		int		bytes_read;
		char	buf_temp[BUFFER_SIZE + 1];
		int		buf_len;

		buf_len = BUFFER_SIZE + 1;
		buf_temp[0] = '\0';
		while (!check_char(static_buf))
		{
			bytes_read = read(fd, buf_temp, BUFFER_SIZE);
			if (bytes_read == -1)
				return (NULL);
			buf_temp[bytes_read] = '\0';
			if (bytes_read == 0)
				break ;
			static_buf = join_buffers(static_buf, buf_temp, &buf_len, bytes_read);
			if (!static_buf)
			{
				printf("1");
				return (NULL);
			}
		}
		return (static_buf);
	}

	char	*get_next_line(int fd)
	{
		static char	*static_buf;
		char		*current_line;
		static int d = 0;

		if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		{
			free(static_buf);
			static_buf = NULL;
			return (NULL);
		}
		d++;
		if (!static_buf)
		{
			static_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (!static_buf)
			{
				printf("2");
				return (NULL);
			}
			static_buf[0] = '\0';
			static_buf = ft_read(static_buf, fd);
		}
		else if (!check_char(static_buf))
			static_buf = ft_read(static_buf, fd);
		if (!static_buf)
			return (NULL);
		current_line = ft_current_line(static_buf);
		static_buf = trim_buf(static_buf, current_line);
		return (current_line);
	}

	// void	leaks(void)
	// {
	// 	system("leaks -q a.out");
	// }

	// int main(void)
	// {
	// 	// atexit(leaks);
	// 	int i = 0;
	// 	int fd = open("test.txt", O_RDONLY);
	// 	char *str = get_next_line(fd);
	// 	while (str)
	// 	{
	// 		// printf("--------------");
	// 		printf("Call: %d\n%s",i ,str);
	// 		// printf("--------------");
	// 		str = get_next_line(fd);
	// 		free(str);
	// 		i++;
	// 	}
	// 	free(str);
	// 	return (0);
	// }