/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:56:22 by verdant           #+#    #+#             */
/*   Updated: 2022/11/12 14:40:49 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>

static char	*trim_buf(char *buf, char *current_line)
{
	int		cur_len;
	int		new_len;
	char	*next_line;

	if (!current_line)
		return (NULL);
	cur_len = ft_strclen(current_line, false);
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
		return (free(buf), NULL);
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
	if (s1_len + s2_len < *size - 1 && s2[0] != '\n')
		return (ft_concat(s1, s2, s1_len, *size));
	*size *= 2;
	target = malloc(*size * sizeof(char));
	if (!target)
		return (free(target), NULL);
	while (s1[i] && i < s1_len)
	{
		target[i] = s1[i];
		i++;
	}
	free(s1);
	ft_concat(target, s2, s1_len, *size);
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
			return (free(static_buf), NULL);
		buf_temp[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		static_buf = join_buffers(static_buf, buf_temp, &buf_len, bytes_read);
		if (!static_buf)
			return (free(static_buf), NULL);
	}
	return (static_buf);
}

char	*get_next_line(int fd)
{
	static char	*static_buf;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(static_buf);
		static_buf = NULL;
		return (NULL);
	}
	if (!static_buf)
	{
		static_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!static_buf)
			return (NULL);
		static_buf[0] = '\0';
		static_buf = ft_read(static_buf, fd);
	}
	else if (!check_char(static_buf))
		static_buf = ft_read(static_buf, fd);
	if (!static_buf)
		return (free(static_buf), NULL);
	current_line = ft_current_line(static_buf);
	static_buf = trim_buf(static_buf, current_line);
	return (current_line);
}

// int main(void)
// {
// 	int fd; 
// 	fd = open("test.txt", O_RDONLY);
// 	int i = 1;
// 	char	*str;
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("--------------\n");
// 		printf("%d: %s",i , str);
// 		printf("--------------\n");
// 		free(str);
// 		str = get_next_line(fd);
// 		i++;
// 	}
// 	return (0);
// }
