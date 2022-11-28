/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/28 19:59:12 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// Problem Statement
	// I declare my tail_a ptr in my main and initialise it createlist
	// that is why I'm able to use it from my main

	// I declare my t_list_b *tail_b in *.oper_b 
	// so I won't be able to reach it from my main

	// Also when I use pushA or pushB I won't be able to access the updated
	// version of tail_a

// Solution Ideas

	// My idea is that what if I create a double pointer and 
	// store each t list a and t list b in that double ptr

	// The question is can you save a stack inside of double ptr
	// There are 3 possible solutions
		// 1. I create tail_b inside of my main with createList func
		// 2. I create a double ptr and point it once to a and then to b
		// 3. I could have an array of structs

	// I could use a int double pointer and store the add. of 
	// tail a and tail b in it. 

	// lul even better I could store tail_a.data and tail_b.data
	// in that int double ptr. and switch around them

int main(int argc, char *argv[])
{
	t_list_a	*tail_a;

	if (!(ft_isdigit(argv, argc)) || !(checkDups(argv, argc)))
		return (1);
	tail_a = createList(tail_a, argv, argc);
}
// Print stuff
	// for (int i = 0; i < 3; i++)
	// {
	// 	printf("%d\t", tail_a->data);
	// 	tail_a = tail_a->prev;
	// }
