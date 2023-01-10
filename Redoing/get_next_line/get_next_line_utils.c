/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:27:51 by verdant           #+#    #+#             */
/*   Updated: 2023/01/10 12:55:45 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strclen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
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