// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_oper_a.c                                 :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/25 11:07:24 by verdant           #+#    #+#             */
// /*   Updated: 2022/11/28 19:21:45 by verdant          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "push_swap.h"

/*			Swap			*/
void	swap(t_list **tail, char c)
{
	int				storeData;


	storeData = (*tail)->data;
	(*tail)->data = (*tail)->prev->data;
	(*tail)->prev->data = storeData;
	if (c == 'a')
		printf("sa\n"); // change to ft_printf later
	else
		printf("sb\n");
}

/*			Rotate			
Top element becomes the bottom one*/
void	rotate(t_list **tail, char c)
{
	int			storeData;
	int			storeSim;
	t_list		*temp_ptr;
	
	storeData = (*tail)->next->data;
	storeSim = (*tail)->next->sim_num;
	temp_ptr = (*tail);

	// Switching bottom node data with top node data
	temp_ptr->next->data = (*tail)->data;
	temp_ptr->next->sim_num = (*tail)->sim_num;

	// Shifting up middle numbers
	while (temp_ptr->prev != (*tail)->next)
	{
		temp_ptr->data = temp_ptr->prev->data;
		temp_ptr->sim_num = temp_ptr->prev->sim_num;
		temp_ptr = temp_ptr->prev;
	}

	// Second to bottom node
	temp_ptr->data = storeData;
	temp_ptr->sim_num = storeSim;
	if (c == 'a')
		printf("ra\n"); // change to ft_printf later
	else
		printf("rb\n");
}

/*			Reverse Rotate			
The bottom element becomes the top element*/
void	reverse_rotate(t_list **tail, char c)
{
	t_list	*temp_ptr;
	int		storeData; // For shifting down
	int		storeData2; // To safeguard prev node data

	temp_ptr = (*tail); // Copy of tail
	storeData = temp_ptr->prev->data;
	temp_ptr->prev->data = temp_ptr->data;
	temp_ptr = temp_ptr->prev;
	while (temp_ptr->prev != (*tail))
	{
		storeData2 = temp_ptr->prev->data; // Storing prev. node data
		temp_ptr->prev->data = storeData; // Shifting down element
		storeData = storeData2; // Setting up element which needs to be shifted
		temp_ptr = temp_ptr->prev; // Decrement ptr
	}
	temp_ptr->prev->data = storeData;
	if (c == 'a')
		printf("rra\n"); // change to ft_printf later
	else
		printf("rrb\n");
}

/*			Push			*/

void	split_top(t_list **tail_take, t_list **tail_put)
{
	t_list *old_last;
	t_list *new_last;

	old_last = *tail_take;
	new_last = (*tail_take)->prev;
	// Pointing tail pointer from stack b to last node of stack a
	*tail_put = old_last; 

	// Cut links
	new_last->next = old_last->next; // Second to top points to bottom
	old_last->next->prev = new_last; // Bottom node points to the new lst

	// Self referencing the last node to it self
	old_last->prev = old_last; 
	old_last->next = old_last;

	// Update tail_take ptr
	(*tail_take) = new_last;
}

void	add_to_put(t_list **stack_take, t_list **stack_put)
{
	t_list	*top_node;
	t_list	*new_last;
	t_list	*old_last_put;

	top_node = *stack_take;
	new_last = (*stack_take)->prev;
	old_last_put = *stack_put;

	new_last->next = top_node->next;
	top_node->next->prev = new_last;
	(*stack_take) = new_last;
	
	top_node->next = old_last_put->next;
	top_node->prev = old_last_put;
	old_last_put->next->prev = top_node;
	old_last_put->next = top_node;
	(*stack_put) = top_node;
}


void	push(t_list **stack_take, t_list **stack_put, char c)
{
	if (!(*stack_take)) // the stack to take from is empty
		return ;
	if (c == 'a')
		printf("pa\n"); // change to ft_printf later
	else
		printf("pb\n");
	if (!(*stack_put)) // the stack to put to is empty
		return (split_top(stack_take, stack_put));
	add_to_put(stack_take, stack_put);
}

// When pushing there are two cases
	// tail_put has a node so it has to be added to the back


		// It has add the top node stack_take to stake_put
		// The links have to be cutted
















// What if tail_take only has one node left?
	// then I have to addBack that to tail_put
	// and set tail_take to NULL