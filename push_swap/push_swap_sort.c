/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:14 by verdant           #+#    #+#             */
/*   Updated: 2022/11/28 19:59:22 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3half(t_list_a *tail_a, int top, int bot)
{
		if (top < bot) // C4
		{
			swapA(tail_a);
			rotateA(tail_a);
		}
		else // C5
			reverseRotateA(tail_a);
}


void	sort3(t_list_a *tail_a)
{
	int	top;
	int	mid;
	int	bot;

	top = tail_a->data;
	mid = tail_a->prev->data;
	bot = tail_a->next->data;
	if (top > mid) // C1 - C3
	{
		if (top > bot && mid < bot) // C3
			rotateA(tail_a);
		else if (top > bot && mid > bot) // C2
		{
			swapA(tail_a);
			reverseRotateA(tail_a);
		}
		else // C1
			swapA(tail_a);
	}
	else
		sort3half(tail_a, top, bot);
}

void	sort5(t_list_a *tail_a, t_list_a *tail_b)
{
	pushB(tail_a, tail_b);
	printf("Can I reach tail b from here: %d", tail_b->data);
}

void	sortSmolStack(t_list_a *tail_a, t_list_b *tail_b)
{
	if (tail_a->size > 3)
		sort5(tail_a, tail_b);
	else
		sort3(tail_a);
}