/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:07:52 by verdant           #+#    #+#             */
/*   Updated: 2022/11/29 19:40:25 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*			Circular Doubly Implementation			*/



bool	add_end(t_list **head, int data)
{
	t_list	*head_node;
	t_list	*new;
	t_list	*last_node;
	
	head_node = *head; // Temp of head;
	new = malloc(sizeof(t_list));
	if (!new)
		return (false);
	new->data = data;
	
	if (!head_node) // If no node created
	{
		*head = new;
		new->prev = new;
		new->next = new;
		return (true);
	}
	last_node = head_node->prev; // Add of last node
	new->next = head_node; // Add of first node
	new->prev = last_node; // Point new last node to the old last node
	head_node->prev = new; // Point head to new last node (Circular)
	last_node->next = new; // Pointing old last node to the new last
	return (true);
}

bool	create_list(t_list **head, char **argv, int argc)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		if (!add_end(head, ft_atoi(argv[i])))
			return (false);
		i--;
	}
	(*head)->size = argc - 1;
	*head = (*head)->prev; // Tracking the last node instead of the first;
	return (true);
}














/*			Circular Singly Implementation			*/

// t_list_a	*firstNode(int data)
// {
// 	t_list_a *temp;
	
// 	temp = malloc(sizeof(t_list_a));
// 	temp->data = data;
// 	temp->next = temp;
// 	return (temp);
// }

// t_list_a	*addEnd(t_list_a *tail, int data)
// {
// 	t_list_a *new;

// 	new = malloc(sizeof(t_list_a));
// 	new->data = data;
	
// 	new->next = tail->next; // New node next pointing to first node
// 	tail->next = new; // Update address of current last node ptr to new last node ptr
// 	tail = tail->next; // Update add. of tail to point to first node
// 	return (tail);
// }

// t_list_a	*createList(t_list_a *tail, char **argv, int argc)
// {
// 	int	i;

// 	tail = firstNode(ft_atoi(argv[1]));
// 	i = 2;
// 	while (i < argc)
// 	{
// 		tail = addEnd(tail, ft_atoi(argv[i]));
// 		i++;
// 	}
// 	return (tail);
// }
