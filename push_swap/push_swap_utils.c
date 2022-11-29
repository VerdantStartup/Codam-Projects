/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:42 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/29 17:58:53 by mwilsch          ###   ########.fr       */
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

// t_list_a	*delLast_A(t_list_a *tail_a)
// {
// 	t_list_a	*temp;
	
// 	temp = tail_a->prev;
// 	temp->next = tail_a->next;
// 	tail_a->next->prev = temp;
// 	tail_a = temp;
// 	return (tail_a);
// }

// t_list_b	*delLast_B(t_list_b *tail_b)
// {
// 	t_list_b	*temp;
	
// 	temp = tail_b->prev;
// 	temp->next = tail_b->next;
// 	tail_b->next->prev = temp;
// 	tail_b = temp;
// 	return (tail_b);
// }
