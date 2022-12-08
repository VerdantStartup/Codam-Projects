/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/08 20:30:58 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// int i = 0;
	// if (is_sorted(&stack_a))
	// {
	// 	while (i < stack_a->size)
	// 	{
	// 		// printf("num = %d\n", stack_a->data);
	// 		stack_a = stack_a->prev;
	// 		i++;
	// 	}
	// }

int	main(int argc, char *argv[]) // Is it okay that my make fclean works even though I alr. cleaned?
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !(ft_isdigit(argv, argc)) || !(check_dups(argv, argc)))
		return (1);
	create_list(&stack_a, argv, argc);
	if (is_sorted(&stack_a))
		return (0);
	if (argc < 5)
		sort_upto_5(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
}
