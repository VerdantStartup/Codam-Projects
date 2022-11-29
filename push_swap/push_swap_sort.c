/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:14 by verdant           #+#    #+#             */
/*   Updated: 2022/11/29 19:53:23 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort3half(t_list_a *tail_a, int top, int bot)
// {
// 		if (top < bot) // C4
// 		{
// 			swapA(tail_a);
// 			rotateA(tail_a);
// 		}
// 		else // C5
// 			reverseRotateA(tail_a);
// }


// void	sort3(t_list **tail)
// {
// 	const int	top = (*tail)->data;
// 	const int	mid = (*tail)->prev->data;
// 	const int	bot = (*tail)->next->data;

// 	if (top > mid) // C1 - C3
// 	{
// 		if (top > bot && mid < bot) // C3
// 			rotateA(tail_a);
// 		else if (top > bot && mid > bot) // C2
// 		{
// 			swapA(tail_a);
// 			reverseRotateA(tail_a);
// 		}
// 		else // C1
// 			swapA(tail_a);
// 	}
// 	else
// 		sort3half(tail_a, top, bot);
// }

// // void	sort5(t_list_a *tail_a, t_list_a *tail_b)
// // {
// // 	pushB(tail_a, tail_b);
// // 	printf("Can I reach tail b from here: %d", tail_b->data);
// // }

// void	sort_upto_5(t_list **stack_a, t_list **stack_b)
// {
// 	if ((*stack_a)->size > 3)
// 		return ; // Not implemented yet
// 	else
// 		sort3(stack_a);
// }