/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:14:57 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/28 19:44:46 by verdant          ###   ########.fr       */
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
}	t_list_a, t_list_b;

// typedef struct size3
// {
// 	int	top;
// 	int	mid;
// 	int	bot;
// }


/*			Utilities			*/
int				ft_atoi(const char *str);
t_list_a	*delLast_A(t_list_a *tail_a);
t_list_b	*delLast_B(t_list_b *tail_b);


/*			Error Handling			*/
bool			checkDups(char **argv, int argc);
bool			ft_isdigit(char **argv, int argc);
int				ft_strcmp(const char *s1, const char *s2);

/*			Parsing Data			*/
t_list_a	*firstNode_A(int data);
t_list_b	*firstNode_B(int data);
t_list_a	*addEnd_A(t_list_a *tail, int data);
t_list_b	*addEnd_B(t_list_b *tail, int data);
t_list_a	*createList(t_list_a *tail, char **argv, int argc);

/*			Operations A			*/
void			swapA(t_list_a *tail);
void			rotateA(t_list_a *tail);
void			reverseRotateA(t_list_a *tail);
void			pushB(t_list_a *tail_a, t_list_b *tail_b);

/*			Operations B			*/
void			swapB(t_list_a *tail_b);
void			rotateB(t_list_a *tail_b);
void			reverseRotateB(t_list_a *tail_b);
void			pushA(t_list_a *tail_b, t_list_b *tail_a);

/*			Sorting			*/
void	sort3(t_list_a *tail_a);
void	sortSmolStack(t_list_a *tail_a, t_list_b *tail_b);

#endif