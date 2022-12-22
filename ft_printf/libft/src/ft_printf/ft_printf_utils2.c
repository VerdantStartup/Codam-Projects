/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:34:29 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/21 16:12:26 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strclen(const char *s, char c)
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

size_t	ft_strlen_printf(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
