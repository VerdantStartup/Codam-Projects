/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/29 21:53:04 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	print(t_list **tail, int argc)
{
	for (int i = 0; i < 1; i++)
	{
		printf("%d\t", (*tail)->data);
		*tail = (*tail)->prev;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	// if (!(ft_isdigit(argv, argc)) || !(checkDups(argv, argc)))
	// 	return (1);
	create_list(&stack_a, argv, argc);
	
	push(&stack_a, &stack_b);
	// push(&stack_b, &stack_a);
	// printf("%d", stack_b->data); // Pushed top element to other stack

	
	push(&stack_a, &stack_b);
	printf("%d", stack_b->next->next->data); // Pushed top element to other stack
	


	
	// print(&stack_b, argc);
	// sort_upto_5(&stack_a, &stack_b);
}
