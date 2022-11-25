/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:07:24 by verdant           #+#    #+#             */
/*   Updated: 2022/11/25 11:16:11 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap first two nodes data keys
	// 1. Traverse to the second to last node
	// 2. Store data of second to last node in temp 
		// int temp = temp_ptr.data
	// 3. Change data of second to last node with last node data
		// temp_ptr.data = temp_ptr.next.data
	// Change last node data
		// temp_ptr.next.data = temp
		