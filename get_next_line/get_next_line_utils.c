/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:02:11 by verdant           #+#    #+#             */
/*   Updated: 2022/11/04 12:49:45 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// If c exists that means we are using strclen then
// we look if c exsits inside of buf
// 1 for yes exists & 0 for no it does not;

int	ft_strclen(char *buf, char c)
{
	int	i;

	i = 0;
	if (c != 0)
	{
		while (buf[i])
		{
			if (buf[i] == c)
				return (i);
			i++;
		}
		return (0);
	}
	else
	{
		while (buf[i])
			i++;
		return (i);
	}
}

// If the if clause is true then we need to concat s2 to 
// at the end of s1

// If not then we need to malloc enough space
// and copy s1 into target and concat s2 at the
// end of target

char	*ft_concat(char *s1, char *s2, size_t s1_len, size_t size)
{
	size_t	i;

	i = 0;
	while (s2[i] && i < size - 1)
	{
		s1[i + s1_len] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return (s1);
}

// ft_substr

char	*ft_substr(char *src, size_t start, size_t len)
{
	char		*target;
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strclen(src, 0);
	target = malloc(len + 1 * sizeof(char));
	if (start + len > src_len)
		len = src_len - start;
	while (i < len)
		target[i++] = src[start++];
	target[i] = '\0';
	return (target);
}
