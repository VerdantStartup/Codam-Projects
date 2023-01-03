/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:42 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/10 17:34:43 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	long int	res;
	int			i;
	int			sign;

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

bool	is_sorted(t_list **stack_a, int size)
{
	t_list	*tail;
	int		i;

	tail = (*stack_a);
	i = 1;
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
