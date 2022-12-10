/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:36:03 by verdant           #+#    #+#             */
/*   Updated: 2022/12/10 17:43:54 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

bool	minus_cnt(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			count++;
		if (count > 1)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_isdigit(char **argv, int argc)
{
	int			i;
	int			j;
	char		*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (str[j])
		{
			if (!(str[j] >= '0' && str[j] <= '9') && str[j] != '-')
				return (false);
			if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
				return (false);
			if (str[j] == '-')
				return (minus_cnt(str));
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_dups(char **argv, int argc)
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
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
