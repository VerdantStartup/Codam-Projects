/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:07:24 by verdant           #+#    #+#             */
/*   Updated: 2022/11/25 19:14:45 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Tail points to the last node

/*			Swap			*/

// Swap first two nodes data keys
	// 1. Traverse to the second to last node
	// 2. Store data of second to last node in temp 
		// int temp = temp_ptr.data
	// 3. Change data of second to last node with last node data
		// temp_ptr.data = temp_ptr.next.data
	// Change last node data
		// temp_ptr.next.data = temp


void	swapA(t_list_a *tail)
{
	int	storeData;

	storeData = tail->data;
	tail->data = tail->prev->data;
	tail->prev->data = storeData;
}


/*			Rotate			*/

// First element becomes last

// 1. Create temp and set it to add. of tail
// 2. Store bottom node's data in storeInt;
// 3. Set botton node data to top node data
	// bottom.data = top.data
// 4. Create while loop
	// Expression ???
		// when temp_ptr.prev == tail.next then stop
	// Steps
		// 1. top_ptr.data = top_ptr.prev.data
		// 2. Decrement top.ptr downoards by one
			// top_ptr = top.prev
		// Do step 1 again
		// Stop when reaching the second node
		// When reaching that node 
			// temp_ptr.data = store Int
void	rotateA(t_list_a *tail)
{
	int				storeData;
	t_list_a	*temp_ptr;
	
	storeData = tail->next->data;
	temp_ptr = tail;

	// Switching bottom node data with top node data
	temp_ptr->next->data = tail->data;

	// Shifting up middle numbers
	while (temp_ptr->prev != tail->next)
	{
		temp_ptr->data = temp_ptr->prev->data;
		temp_ptr = temp_ptr->prev;
	}

	// Second to bottom node
	temp_ptr->data = storeData;
}

/*			Reverse Rotate			*/

void	reverseRotateA(t_list_a *tail)
{
	t_list_a	*temp_ptr;
	int	storeData;
	int	storeData2;

	temp_ptr = tail;
	storeData = temp_ptr->prev->data;
	temp_ptr->prev->data = temp_ptr->data;
	temp_ptr = temp_ptr->prev;
	while (temp_ptr->prev != tail)
	{
		storeData2 = temp_ptr->prev->data;
		temp_ptr->prev->data = storeData;
		storeData = storeData2;
		temp_ptr = temp_ptr->prev;
	}
	temp_ptr->prev->data = storeData;
}