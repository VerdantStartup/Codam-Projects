/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:14 by verdant           #+#    #+#             */
/*   Updated: 2022/12/08 20:09:02 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Order in sort3 --> C3 -> C2 -> C1 | else --> C4 -> C%

void	sort3(t_list **tail)
{
	const int	top = (*tail)->data;
	const int	mid = (*tail)->prev->data;
	const int	bot = (*tail)->next->data;

	if (top > mid)
	{
		if (top > bot && mid < bot)
			rotate(tail, 'a');
		else if (top > bot && mid > bot)
			return (swap(tail, 'a'), reverse_rotate(tail, 'a'));
		else
			swap(tail, 'a');
	}
	else
	{
		if (top < bot)
			return (swap(tail, 'a'), rotate(tail, 'a'));
		else
			reverse_rotate(tail, 'a');
	}
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i++ < 2)
		push(stack_a, stack_b, 'a');
	sort3(stack_a);
	if ((*stack_b)->data > (*stack_b)->prev->data)
		swap(stack_b, 'b');
	while (i < 5)
	{
		push(stack_b, stack_a, 'b');
		rotate(stack_a, 'a');
		i++;
	}
}

void	sort_upto_5(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->size > 3)
		sort5(stack_a, stack_b);
	else
		sort3(stack_a);
}
