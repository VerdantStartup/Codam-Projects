/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:07:52 by verdant           #+#    #+#             */
/*   Updated: 2022/11/28 19:44:56 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*			Circular Doubly Implementation			*/

t_list_a	*firstNode_A(int data)
{
	t_list_a	*temp = malloc(sizeof(t_list_a));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	return (temp);
}

t_list_b	*firstNode_B(int data)
{
	t_list_b	*temp = malloc(sizeof(t_list_b));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	return (temp);
}

t_list_a *addEnd_A(t_list_a *tail_a, int data)
{
	t_list_a	*temp;
	t_list_a	*new;

	temp = tail_a->next; // First node address
	new = malloc(sizeof(t_list_a));
	
	// Initalsing node
	new->prev = NULL;
	new->data = data;
	new->next = NULL;

	// Updating Pointers
	new->prev = tail_a; // Address of old last node
	new->next = temp; // Address of first node
	temp->prev = new; // First node prev pointing to last node
	tail_a->next = new; // Pointing old last node to new last node
	tail_a = new; // Tail_a now points to last node
	return (tail_a);
}

t_list_b *addEnd_B(t_list_b *tail_b, int data)
{
	t_list_b	*temp;
	t_list_b	*new;

	temp = tail_b->next; // First node address
	new = malloc(sizeof(t_list_b));
	
	// Initalsing node
	new->prev = NULL;
	new->data = data;
	new->next = NULL;

	// Updating Pointers
	new->prev = tail_b; // Address of old last node
	new->next = temp; // Address of first node
	temp->prev = new; // First node prev pointing to last node
	tail_b->next = new; // Pointing old last node to new last node
	tail_b = new; // Tail_b now points to last node
	return (tail_b);
}

t_list_a	*createList(t_list_a *tail_a, char **argv, int argc)
{
	int	i;

	tail_a = firstNode_A(ft_atoi(argv[argc - 1]));
	i = argc - 2;
	while (i > 0)
	{
		tail_a = addEnd_A(tail_a, ft_atoi(argv[i]));
		i--;
	}
	tail_a->size = argc;
	return (tail_a);
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
