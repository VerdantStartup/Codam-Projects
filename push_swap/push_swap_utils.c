/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:42 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/08 20:05:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (res == 0)
		return (0);
	return (res * sign);
}

bool	is_sorted(t_list **stack_a)
{
	t_list	*tail;
	int		i;
	int		size;

	tail = (*stack_a);
	i = 1;
	size = tail->size;
	while (i < size)
	{
		if (tail->data < tail->prev->data)
			i++;
		else
			return (false);
		tail = tail->prev;
	}
	return (true);
}

int	lst_size(t_list **tail)
{
	int		counter;
	t_list	*temp;

	counter = 0;
	temp = (*tail);
	while (temp != (*tail)->next)
	{
		counter++;
		temp = temp->prev;
	}
	return (counter + 1);
}
