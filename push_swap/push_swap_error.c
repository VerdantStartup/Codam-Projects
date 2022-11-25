/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:36:03 by verdant           #+#    #+#             */
/*   Updated: 2022/11/25 10:02:18 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s2[i] > (unsigned char)s1[i])
			return (-1);
		i++;
	}
	return (0);
}

bool	ft_isdigit(char **argv, int argc)
{
	int		i;
	int		j;
	char	*str;
	
	i = 1;
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (str[j])
		{
			if (!(str[j] >= '0' && str[j] <= '9'))
			{
				printf("Error"); // Change to ft_printf later
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	checkDups(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
			{
				printf("Error"); // Change to ft_printf later
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

