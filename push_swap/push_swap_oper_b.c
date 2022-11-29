// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_oper_b.c                                 :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/26 12:21:11 by verdant           #+#    #+#             */
// /*   Updated: 2022/11/26 12:55:09 by verdant          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void	swapB(t_list_a *tail_b)
// {
// 	int	storeData;

// 	storeData = tail_b->data;
// 	tail_b->data = tail_b->prev->data;
// 	tail_b->prev->data = storeData;
// }

// void	rotateB(t_list_a *tail_b)
// {
// 	int				storeData;
// 	t_list_a	*temp_ptr;
	
// 	storeData = tail_b->next->data;
// 	temp_ptr = tail_b;

// 	// Switching bottom node data with top node data
// 	temp_ptr->next->data = tail_b->data;

// 	// Shifting up middle numbers
// 	while (temp_ptr->prev != tail_b->next)
// 	{
// 		temp_ptr->data = temp_ptr->prev->data;
// 		temp_ptr = temp_ptr->prev;
// 	}

// 	// Second to bottom node
// 	temp_ptr->data = storeData;
// }

// void	reverseRotateB(t_list_a *tail_b)
// {
// 	t_list_a	*temp_ptr;
// 	int	storeData;
// 	int	storeData2;

// 	temp_ptr = tail_b;
// 	storeData = temp_ptr->prev->data;
// 	temp_ptr->prev->data = temp_ptr->data;
// 	temp_ptr = temp_ptr->prev;
// 	while (temp_ptr->prev != tail_b)
// 	{
// 		storeData2 = temp_ptr->prev->data;
// 		temp_ptr->prev->data = storeData;
// 		storeData = storeData2;
// 		temp_ptr = temp_ptr->prev;
// 	}
// 	temp_ptr->prev->data = storeData;
// }

// void	pushA(t_list_b *tail_b, t_list_a *tail_a)
// {
// 	if (!tail_a)
// 		tail_a = firstNode_A(tail_b->data);
// 	else
// 		tail_a = addEnd_A(tail_a, tail_b->data);
// 	tail_b = delLast_B(tail_b);
// }