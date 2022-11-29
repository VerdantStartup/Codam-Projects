/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:14:57 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/29 20:20:26 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h> // <-- Delete after before handing in the project

// A double ptr of the tails of the stakcs is recommend to be able to change stuff

/*			Stacks			*/

typedef struct stack
{
	struct	stack *prev;
	int			data;
	int			size;
	struct	stack *next;
}	t_list;

// typedef struct size3
// {
// 	int	top;
// 	int	mid;
// 	int	bot;
// }


/*			Utilities			*/
int		ft_atoi(const char *str);
// t_list_a	*delLast_A(t_list_a *tail_a);
// t_list_b	*delLast_B(t_list_b *tail_b);


/*			Error Handling			*/
bool	checkDups(char **argv, int argc);
bool	ft_isdigit(char **argv, int argc);
int		ft_strcmp(const char *s1, const char *s2);

/*			Parsing Data			*/
bool	add_end(t_list **head, int data);
bool	create_list(t_list **head, char **argv, int argc);

/*			Operations			*/
void	swap(t_list **tail);
void	rotate(t_list **tail);
void	reverse_rotate(t_list **tail);
void	push(t_list **tail_take, t_list **tail_put);
// void	pushB(t_list_a *tail_a, t_list_b *tail_b);

/*			Operations B			*/
// void	swapB(t_list_a *tail_b);
// void	rotateB(t_list_a *tail_b);
// void	reverseRotateB(t_list_a *tail_b);
// void	pushA(t_list_a *tail_b, t_list_b *tail_a);

/*			Sorting			*/
void	sort_upto_5(t_list **stack_a, t_list **stack_b);

#endif