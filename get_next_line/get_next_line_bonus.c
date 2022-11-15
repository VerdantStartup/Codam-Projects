/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:38:30 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/14 21:03:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*trim_buf(char *buf, char *current_line)
{
	int		cur_len;
	char	*next_line;
	int		i;

	i = 0;
	if (!current_line)
		return (NULL);
	cur_len = ft_strclen(current_line, false);
	next_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!next_line)
		return (free(buf), NULL);
	while (buf[cur_len + i])
	{
		next_line[i] = buf[cur_len + i];
		i++;
	}
	next_line[i] = '\0';
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
	if (s1_len + s2_len < *size - 1 && s2[0] != '\n' && s1[i])
		return (ft_concat(s1, s2, s1_len));
	*size *= 2;
	target = malloc(*size * sizeof(char));
	if (!target)
		return (NULL);
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
		if (bytes_read == 0)
			break ;
		buf_temp[bytes_read] = '\0';
		static_buf = join_buffers(static_buf, buf_temp, &buf_len, bytes_read);
		if (!static_buf)
			return (NULL);
	}
	return (static_buf);
}

char	*get_next_line(int fd)
{
	static char	*static_buf[OPEN_MAX];
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(static_buf[fd]);
		static_buf[fd] = NULL;
		return (NULL);
	}
	if (!static_buf[fd])
	{
		static_buf[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		ft_bzero(static_buf[fd], BUFFER_SIZE + 1);
		if (!static_buf[fd])
			return (NULL);
		static_buf[fd] = ft_read(static_buf[fd], fd);
	}
	else if (!check_char(static_buf[fd]))
		static_buf[fd] = ft_read(static_buf[fd], fd);
	if (!static_buf[fd])
		return (NULL);
	current_line = ft_current_line(static_buf[fd]);
	static_buf[fd] = trim_buf(static_buf[fd], current_line);
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
