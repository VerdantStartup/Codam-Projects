/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:07:52 by verdant           #+#    #+#             */
/*   Updated: 2022/12/10 17:43:41 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*			Circular Doubly Implementation			*/

void	fill_data(t_list **head, int i, int argc)
{	
	i = 0;
	while (--argc > 0)
	{
		(*head)->sim_num = -1;
		*head = (*head)->prev;
		i++;
	}
}

// Add of last node
// Add of first node
// Point new last node to the old last node
// Point head to new last node (Circular)
// Pointing old last node to the new last

bool	add_end(t_list **head, int data)
{
	t_list		*head_node;
	t_list		*new;
	t_list		*last_node;

	head_node = *head;
	new = malloc(sizeof(t_list));
	if (!new)
		return (false);
	new->data = data;
	if (!head_node)
	{
		*head = new;
		new->prev = new;
		new->next = new;
		return (true);
	}
	last_node = head_node->prev;
	new->next = head_node;
	new->prev = last_node;
	head_node->prev = new;
	last_node->next = new;
	return (true);
}

// Tracking the last node instead of the first;
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
	*head = (*head)->prev;
	fill_data(head, i, argc);
	return (true);
}
