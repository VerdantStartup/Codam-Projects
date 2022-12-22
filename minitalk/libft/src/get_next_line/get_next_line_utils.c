/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:02:11 by verdant           #+#    #+#             */
/*   Updated: 2022/11/15 16:01:55 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int	ft_strclen(char *buf, bool search_newline)
{
	int	i;

	i = 0;
	if (search_newline)
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
				return (i);
			i++;
		}
		return (0);
	}
	while (buf[i])
		i++;
	return (i);
}

char	*ft_concat(char *s1, char *s2, int s1_len)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i + s1_len] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return (s1);
}

char	*ft_substr(char *src, int start, int len)
{
	char	*target;
	int		i;
	int		src_len;

	i = 0;
	src_len = ft_strclen(src, false);
	if (start + len > src_len)
		len = src_len - start;
	target = malloc((len + 1) * sizeof(char));
	if (!target)
		return (NULL);
	while (i < len)
	{
		target[i] = src[start];
		i++;
		start++;
	}
	target[i] = '\0';
	return (target);
}

int	check_char(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
