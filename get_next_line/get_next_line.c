/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:56:22 by verdant           #+#    #+#             */
/*   Updated: 2022/11/02 15:55:20 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_next_line(char *buf, char *current_line)
{
	size_t	cur_len;
	size_t	new_len;
	char		*next_line;

	cur_len = ft_strclen(current_line, 0);
	new_len = ft_strclen(buf, 0) - cur_len;
	next_line = ft_substr(buf, cur_len, new_len);
	return (next_line);
}

char	*ft_current_line(char *buf)
{
	char		*current_line;
	size_t	line_len;

	if (!buf)
		return (NULL);
	line_len = ft_strclen(buf, '\n');
	if (line_len)
		current_line = ft_substr(buf, 0 , 1 + line_len);
	else
		current_line = ft_substr(buf, 0, ft_strclen(buf, 0));
	free(buf);
	return (current_line);
}

char	*join_buffers(char *s1, char *s2,size_t *size, int s2_len)
{
	const int	s1_len = ft_strclen(s1, 0);
	char			*target;
	int				i; 

	i = 0;
	if (s1_len + s2_len < *size)
	{
		ft_concat(s1, s2, s1_len, *size);
		return (s1);
	}
	*size *= 2;
	target = malloc(*size * sizeof(char));
	if (!target)
		return (NULL);
	while (s1[i] && i < s1_len)
	{
		target[i] = s1[i];
		i++;
	}
	ft_concat(target, s2, s1_len, *size);
	return (target);
}


char	*ft_read(char *static_buf, int fd)
{
	int			bytes_read;
	char		buf_temp[BUFFER_SIZE + 1];
	size_t	buf_temp_len;

	buf_temp_len = BUFFER_SIZE + 1;
	while (!ft_strclen(buf_temp, '\n'))
	{
		bytes_read = read(fd, buf_temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if(bytes_read == 0)
			break;
		buf_temp[bytes_read] = '\0';
		static_buf = join_buffers(static_buf, buf_temp, &buf_temp_len, bytes_read);
	}
	return (static_buf);
}


char	*get_next_line(int fd)
{
	static char	*static_buf;
	char				*current_line;

	if (!static_buf)
	{
		static_buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!static_buf)
			return (NULL);
		static_buf[0] = '\0';
		static_buf = ft_read(static_buf, fd);
	}
	else if (!ft_strclen(static_buf, '\n'))
		static_buf = ft_read(static_buf, fd);
	current_line = ft_current_line(static_buf);
	static_buf = ft_next_line(static_buf, current_line);
	return (current_line);
}


int main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	int i = 0;
	// get_next_line(fd);
	while (i < 4)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}