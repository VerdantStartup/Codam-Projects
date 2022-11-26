/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/26 12:33:21 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// void	print_a(t_list_a *tail_a)
// {
// 	printf("In main: %d\n", tail_a->data);
// 	// printf("Mid: %d\n", tail_a->prev->data);
// 	// printf("Bot: %d\n", tail_a->prev->prev->data);
// 	// printf("Bottom: %d\n\n", tail_a->prev->prev->prev->data);
// }

int main(int argc, char *argv[])
{
	bool			onlyInts;
	bool			noDups;
	t_list_a	*tail_a;

	if (!(onlyInts = ft_isdigit(argv, argc)) || !(noDups = checkDups(argv, argc)))
		return (0);
	tail_a = createList(tail_a, argv, argc);
	
}
