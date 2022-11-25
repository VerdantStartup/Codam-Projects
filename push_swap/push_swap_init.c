/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:07:52 by verdant           #+#    #+#             */
/*   Updated: 2022/11/25 11:42:43 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*firstNode(int data)
{
	t_list_a *temp;
	
	temp = malloc(sizeof(t_list_a));
	temp->data = data;
	temp->next = temp;
	return (temp);
}

t_list_a	*addEnd(t_list_a *tail, int data)
{
	t_list_a *new;

	new = malloc(sizeof(t_list_a));
	new->data = data;
	
	new->next = tail->next; // New node next pointing to first node
	tail->next = new; // Update address of current last node ptr to new last node ptr
	tail = tail->next; // Update add. of tail to point to first node
	return (tail);
}

t_list_a	*createList(t_list_a *tail, char **argv, int argc)
{
	int	i;

	tail = firstNode(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		tail = addEnd(tail, ft_atoi(argv[i]));
		i++;
	}
	return (tail);
}
