/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:29 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/08 20:16:52 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_max(t_list **stack_a)
{
	int	size;
	int	max_num;

	size = (*stack_a)->size;
	max_num = (*stack_a)->data;
	while (size)
	{
		if (max_num < (*stack_a)->data)
			max_num = (*stack_a)->data;
		*stack_a = (*stack_a)->prev;
		size--;
	}
	(*stack_a)->max_num = max_num;
	return (max_num);
}

void	simplify(t_list **stack_a)
{
	int			size;
	int			i;
	long int	max_num;
	t_list		*node_smol;
	t_list		*temp;

	i = 0;
	max_num = num_max(stack_a);
	node_smol = (*stack_a);
	temp = (*stack_a);
	while (i < (*stack_a)->size)
	{
		while (size)
		{
			if ((node_smol->data_copy > temp->data) && (temp->flag != 'y'))
				node_smol = temp;
			temp = temp->prev;
			size--;
		}
		node_smol->sim_num = i;
		node_smol->flag = 'y';
		node_smol->data_copy = max_num + 1;
		size = temp->size;
		i++;
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		size_of_b;
	int		num;

	i = 0;
	simplify(stack_a);
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j < (*stack_a)->size)
		{
			num = (*stack_a)->sim_num;
			if (((num >> i) & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		i++;
		size_of_b = lst_size(stack_b);
		while (size_of_b--)
			push(stack_b, stack_a, 'a');
	}
}
