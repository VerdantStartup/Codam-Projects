/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:07:24 by verdant           #+#    #+#             */
/*   Updated: 2022/11/25 15:44:18 by verdant          ###   ########.fr       */
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
	// printf("Before swap: Last node: |%d|\t", tail->data);
	// printf("Second to last node: |%d|\n\n", tail->prev->data);

	int	storeData;

	storeData = tail->data; // Last node's data
	tail->data = tail->prev->data;
	tail->prev->data = storeData;

	// printf("After swap: Last node: |%d|\t", tail->data);
	// printf("Second to last node: |%d|", tail->prev->data);
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
	int	storeData;
	t_list_a *temp_ptr;
	
	storeData = tail->next->data;
	temp_ptr = tail;


	// Switching bottom node data with top node data
	// temp_ptr->next->data = tail->data;

	// Switching last node data with prev node data
		// temp_ptr->data = temp_ptr->prev->data;
	// while (temp_ptr->prev != tail->next)
	// {
	// 	temp_ptr->data = temp_ptr->prev->data;
	// 	temp_ptr = temp_ptr->prev;
	// }

	// printing to test
	t_list_a *p = tail->next;
	printf("%d", tail->data);
	// do
	// {
	// 	printf("%d\n", p->data);
	// 	p = p->next;
	// } while (p != tail->next);
}
