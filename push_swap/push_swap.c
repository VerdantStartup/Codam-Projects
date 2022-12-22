/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/22 14:18:07 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// !!!!!!!!


// This is not the version I handed in or in other words
// this is not the newst version. the newst version is 
// saved locally in Codam. I have to add it to my Github
// When I'm back in Amsterddam



/// !!!!!!!!






#include "push_swap.h"
#include <stdio.h>

void	print(t_list **tail)
{
	int size = lst_size(tail);
	t_list *temp = (*tail);
	for (int i = 0; i < size; i++)
	{
		printf("%p\n", temp);
		temp = temp->prev;
	}
}

void	leaks(void)
{
	system("leaks -q a.out");
}

int	main(int argc, char *argv[]) // Is it okay that my make fclean works even though I alr. cleaned?
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list *temp;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = argc - 1;
	if (argc == 1 || !(ft_isdigit(argv, argc)) || !(check_dups(argv, argc)))
	{
		write(2,"Error\n", 6);
		return (1);
	}
	create_list(&stack_a, argv, argc);
	if (is_sorted(&stack_a, size))
		return (0);
	if (size <= 5)
		sort_upto_5(&stack_a, &stack_b, size);
	else
		sort_big(&stack_a, &stack_b, size);
		
	while (size > 0)
	{
		temp = stack_a;
		stack_a = stack_a->prev;
		free(temp);
		size--;
	}
	atexit(leaks);
}