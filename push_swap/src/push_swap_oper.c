/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:23:58 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/10 18:12:17 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Switching bottom node data with top node data
// Shifting up middle numbers
// Second to bottom node

/*			Rotate			
Top element becomes the bottom one*/
void	rotate(t_list **tail, char c)
{
	int			store_data;
	int			store_sim;
	t_list		*temp_ptr;

	store_data = (*tail)->next->data;
	store_sim = (*tail)->next->sim_num;
	temp_ptr = (*tail);
	temp_ptr->next->data = (*tail)->data;
	temp_ptr->next->sim_num = (*tail)->sim_num;
	while (temp_ptr->prev != (*tail)->next)
	{
		temp_ptr->data = temp_ptr->prev->data;
		temp_ptr->sim_num = temp_ptr->prev->sim_num;
		temp_ptr = temp_ptr->prev;
	}
	temp_ptr->data = store_data;
	temp_ptr->sim_num = store_sim;
	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

// For shifting down
// To safeguard prev node data
//The bottom element becomes the top element*/
// Storing prev. node data
// Shifting down element
// Setting up element which needs to be shifted

/*			Reverse Rotate			 */
void	reverse_rotate(t_list **tail, char c)
{
	t_list	*temp_ptr;
	int		store_data;
	int		store_data2;

	temp_ptr = (*tail);
	store_data = temp_ptr->prev->data;
	temp_ptr->prev->data = temp_ptr->data;
	temp_ptr = temp_ptr->prev;
	while (temp_ptr->prev != (*tail))
	{
		store_data2 = temp_ptr->prev->data;
		temp_ptr->prev->data = store_data;
		store_data = store_data2;
		temp_ptr = temp_ptr->prev;
	}
	temp_ptr->prev->data = store_data;
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

// Pointing tail pointer from stack b to last node of stack a
// Cut links
// Second to top points to bottom
// Bottom node points to the new lst
// Self referencing the last node to it self
// Update tail_take ptr
/*			Push			*/
void	split_top(t_list **tail_take, t_list **tail_put)
{
	t_list	*old_last;
	t_list	*new_last;

	old_last = *tail_take;
	new_last = (*tail_take)->prev;
	*tail_put = old_last;
	new_last->next = old_last->next;
	old_last->next->prev = new_last;
	old_last->prev = old_last;
	old_last->next = old_last;
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
	if (!(*stack_take))
		return ;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	if (!(*stack_put))
		return (split_top(stack_take, stack_put));
	add_to_put(stack_take, stack_put);
}
