/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/25 11:44:21 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
	bool			onlyInts;
	bool			noDups;
	t_list_a	*tail;

	if (!(onlyInts = ft_isdigit(argv, argc)) || !(noDups = checkDups(argv, argc)))
		return (0);
	tail = createList(tail, argv, argc);

}

// Tester main

// int main(int argc, char *argv[])
// {
// 	bool			onlyInts;
// 	bool			noDups;
// 	t_list_a	*tail;

// 	if (!(onlyInts = ft_isdigit(argv, argc)) || !(noDups = checkDups(argv, argc)))
// 		return (0);
	
// 	// testing parsing
// 	tail = createList(tail, argv, argc);
// 	t_list_a *p = tail->next;
// 	do
// 	{
// 		printf("%d\n", p->data);
// 		p = p->next;
// 	} while (p != tail->next);
// }
