/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oper_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:07:24 by verdant           #+#    #+#             */
/*   Updated: 2022/11/26 12:32:42 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Tail points to the last node

/*			Swap			*/
void	swapA(t_list_a *tail_a)
{
	int	storeData;

	storeData = tail_a->data;
	tail_a->data = tail_a->prev->data;
	tail_a->prev->data = storeData;
}

/*			Rotate			*/
void	rotateA(t_list_a *tail_a)
{
	int				storeData;
	t_list_a	*temp_ptr;
	
	storeData = tail_a->next->data;
	temp_ptr = tail_a;

	// Switching bottom node data with top node data
	temp_ptr->next->data = tail_a->data;

	// Shifting up middle numbers
	while (temp_ptr->prev != tail_a->next)
	{
		temp_ptr->data = temp_ptr->prev->data;
		temp_ptr = temp_ptr->prev;
	}

	// Second to bottom node
	temp_ptr->data = storeData;
}

/*			Reverse Rotate			*/
void	reverseRotateA(t_list_a *tail_a)
{
	t_list_a	*temp_ptr;
	int	storeData;
	int	storeData2;

	temp_ptr = tail_a;
	storeData = temp_ptr->prev->data;
	temp_ptr->prev->data = temp_ptr->data;
	temp_ptr = temp_ptr->prev;
	while (temp_ptr->prev != tail_a)
	{
		storeData2 = temp_ptr->prev->data;
		temp_ptr->prev->data = storeData;
		storeData = storeData2;
		temp_ptr = temp_ptr->prev;
	}
	temp_ptr->prev->data = storeData;
}

/*			Push B			*/

// Problem
	// Is it a problem that in I can't reach the pointer
	// from my main?

void	pushB(t_list_a *tail_a, t_list_b *tail_b)
{
	if (!tail_b)
		tail_b = firstNode_B(tail_a->data);
	else
		tail_b = addEnd_B(tail_b, tail_a->data);
	tail_a = delLast_A(tail_a);
}

// t_list_b	*pushB(t_list_a *tail_a, t_list_b *tail_b)
// {
// 	if (!tail_b)
// 	{
// 		tail_b = firstNode_B(tail_a->data);
// 		tail_a = delLast_A(tail_a);
// 	}
// 	else
// 	{
// 		tail_b = addEnd_B(tail_b, tail_a->data);
// 		tail_a = delLast_A(tail_a);
// 	}
// 	return (tail_b);
// }