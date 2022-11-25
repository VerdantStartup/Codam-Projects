/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:07:52 by verdant           #+#    #+#             */
/*   Updated: 2022/11/25 18:12:24 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*			Circular Doubly Implementation			*/

t_list_a	*firstNode(int data)
{
	t_list_a	*temp = malloc(sizeof(t_list_a));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	return (temp);
}

t_list_a *addEnd(t_list_a *tail, int data)
{
	t_list_a	*temp;
	t_list_a	*new;

	temp = tail->next; // First node address
	new = malloc(sizeof(t_list_a));
	
	// Initalsing node
	new->prev = NULL;
	new->data = data;
	new->next = NULL;

	// Updating Pointers
	new->prev = tail; // Address of old last node
	new->next = temp; // Address of first node
	temp->prev = new; // First node prev pointing to last node
	tail->next = new; // Pointing old last node to new last node
	tail = new; // Tail now points to last node
	return (tail);
}

// I'm not sure if I parsed numbers the right way or the wrong way around

// Parsing the end of argv to start

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

// Parsing from start of argv to end

t_list_a	*createList(t_list_a *tail, char **argv, int argc)
{
	int	i;

	tail = firstNode(ft_atoi(argv[argc - 1]));
	i = argc - 2;
	while (i > 0)
	{
		tail = addEnd(tail, ft_atoi(argv[i]));
		i--;
	}
	return (tail);
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
