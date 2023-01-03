/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:14 by verdant           #+#    #+#             */
/*   Updated: 2023/01/03 19:12:41 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

// Order in sort3 --> C3 -> C2 -> C1 | else --> C4 -> C%

void	sort3(t_list **tail, int size)
{
	const int	top = (*tail)->data;
	const int	mid = (*tail)->prev->data;
	const int	bot = (*tail)->next->data;

	if (is_sorted(tail, size) == true)
		return ;
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

void	small_to_b(t_list **stack_a, t_list **stack_b, int small)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = (*stack_a);
	while (small != temp->data)
	{
		temp = temp->prev;
		i++;
	}
	if (i < 3)
	{
		while ((*stack_a)->data != small)
			rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
	else
	{
		while ((*stack_a)->data != small)
			reverse_rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
}

void	sort5(t_list **stack_a, t_list **stack_b, int size)
{
	int		cnt;
	int		small;
	t_list	*temp;

	cnt = 0;
	small = INT_MAX;
	temp = (*stack_a);
	while (cnt < lst_size(stack_a))
	{
		if ((*stack_a)->data < small)
			small = (*stack_a)->data;
		*stack_a = (*stack_a)->prev;
		cnt++;
	}
	if ((*stack_a)->data == small)
		push(stack_a, stack_b, 'b');
	else
		small_to_b(stack_a, stack_b, small);
}


// This version accounts for list size 4 or 5 unlike the other one which always
// Just switches the 2 numberes to sort 5 and 2 to pa
// I guess it still works but let's see...

void	sort_upto_5(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;

	i = 0;
	if (size > 3)
	{
		while (lst_size(stack_a) > 3)
		{
			sort5(stack_a, stack_b, size);
			i++;
		}
		sort3(stack_a, lst_size(stack_a));
		while (lst_size(stack_a) <= size - 1)
		{
			push(stack_b, stack_a, 'a');
			i++;
		}
	}
	else
		sort3(stack_a, size);
}
