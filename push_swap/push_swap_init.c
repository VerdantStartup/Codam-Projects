/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:07:52 by verdant           #+#    #+#             */
/*   Updated: 2022/12/08 12:50:19 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*			Circular Doubly Implementation			*/

void	fill_data(t_list **head, int i, int argc)
{
	const int	size = argc - 1;
	
	i = 0;
	while (--argc > 0)
	{
		// (*head)->index = i;
		(*head)->flag = 'n';
		(*head)->size = size;
		(*head)->data_copy = (*head)->data;
		*head = (*head)->prev;
		i++;
	}
}


bool	add_end(t_list **head, int data)
{
	t_list		*head_node;
	t_list		*new;
	t_list		*last_node;
	
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
	*head = (*head)->prev; // Tracking the last node instead of the first;
	fill_data(head,i ,  argc);
	return (true);
}
