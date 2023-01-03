/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:29 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/10 16:31:54 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// int	num_max(t_list **stack_a)
// {
// 	int	size;
// 	int	max_num;

// 	size = (*stack_a)->size;
// 	max_num = (*stack_a)->data;
// 	while (size)
// 	{
// 		if (max_num < (*stack_a)->data)
// 			max_num = (*stack_a)->data;
// 		*stack_a = (*stack_a)->prev;
// 		size--;
// 	}
// 	return (max_num);
// }

// simplfify my simplify function lul, I use to many vars in my linked list
// find another way to normalise numbs

void	simplify(t_list **stack_a, int size, int size2)
{
	int			i;
	int			smol;
	int			cur_smol;
	t_list		*node_smol;

	i = 0;
	smol = INT_MIN;
	node_smol = (*stack_a);
	while (i < size)
	{
		cur_smol = INT_MAX;
		while (size--)
		{
			if ((smol < (*stack_a)->data) && ((*stack_a)->data < cur_smol))
			{
				node_smol = *stack_a;
				cur_smol = (*stack_a)->data;
			}
			(*stack_a) = (*stack_a)->prev;
		}
		node_smol->sim_num = i;
		smol = node_smol->data;
		size = size2;
		i++;
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	int		j;
	int		size_of_b;
	int		num;
	int		size2;

	i = 0;
	size2 = size;
	simplify(stack_a, size, size2);
	while (!is_sorted(stack_a, size))
	{
		j = 0;
		while (j++ < size)
		{
			num = (*stack_a)->sim_num;
			if (((num >> i) & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		i++;
		size_of_b = lst_size(stack_b);
		while (size_of_b--)
			push(stack_b, stack_a, 'a');
	}
}
