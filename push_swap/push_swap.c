/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/08 19:46:41 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	lst_size(t_list **tail)
{
	int	counter;
	t_list	*temp;

	counter = 0;
	temp = (*tail);
	while (temp != (*tail)->next)
	{
		counter++;
		temp = temp->prev;
	}
	return (counter + 1);
}


void	print(t_list **tail)
{
	if ((*tail) == NULL)
	{
		printf("Empty");
		return ;
	}
	int	d = lst_size(tail);
	for (int i = 0; i < d; i++)
	{
		printf("%d: Data: %d\n", i, (*tail)->data);
		printf("%d: Sim:  %d\n\n", i, (*tail)->sim_num);
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
	printf("%s", argv[0][0])
	// if (argc == 1 || !(ft_isdigit(argv, argc)) || !(checkDups(argv, argc)))
	// 	return (1);
	// create_list(&stack_a, argv, argc);	
	// if (is_sorted(&stack_a))
	// 	return (0);
	// if (argc < 5)
	// 	sort_upto_5(&stack_a, &stack_b);
	// else
	// 	sort_big(&stack_a, &stack_b);
	
}


	// int i = 0;
	// // if (is_sorted(&stack_a))
	// // {
	// // 	while (i < stack_a->size)
	// // 	{
	// // 		// printf("num = %d\n", stack_a->data);
	// // 		stack_a = stack_a->prev;
	// // 		i++;
	// // 	}
		
	// // }