/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/03 19:06:26 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	leaks(void)
// {
// 	system("leaks -q a.out");
// }

#include <stdio.h>
void	print(t_list **tail)
{
	int size = lst_size(tail);
	t_list *temp = (*tail);
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

/*			Swap			*/
void	swap(t_list **tail, char c)
{
	int				store_data;

	store_data = (*tail)->data;
	(*tail)->data = (*tail)->prev->data;
	(*tail)->prev->data = store_data;
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	free_list(t_list **stack_a, int size)
{
	t_list	*temp;

	temp = (*stack_a);
	while (size > 0)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->prev;
		free(temp);
		size--;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = argc - 1;
	if (argc == 1 || !(ft_isdigit(argv, argc)) || !(check_dups(argv, argc)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	create_list(&stack_a, argv, argc);
	if (is_sorted(&stack_a, size))
		return (0);
	if (size <= 5)
		sort_upto_5(&stack_a, &stack_b, size);
	else
		sort_big(&stack_a, &stack_b, size);
	free_list(&stack_a, size);
}
