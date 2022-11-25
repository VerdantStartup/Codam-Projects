/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:14:57 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/25 15:23:32 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h> // <-- Delete after before handing in the project

/*			Stacks			*/

// typedef struct s_list
// {
// 	int			data;
// 	struct	s_list *next;
// }	t_list_a;

typedef struct s_list
{
	struct	s_list *prev;
	int			data;
	struct	s_list *next;
}	t_list_a;

/*			Utilities			*/
int		ft_atoi(const char *str);

/*			Error Handling			*/
bool	checkDups(char **argv, int argc);
bool	ft_isdigit(char **argv, int argc);
int		ft_strcmp(const char *s1, const char *s2);

/*			Parsing Data			*/
t_list_a	*firstNode(int data);
t_list_a	*addEnd(t_list_a *tail, int data);
t_list_a	*createList(t_list_a *tail, char **argv, int argc);


/*			Operations			*/
void	swapA(t_list_a *tail);
void	rotateA(t_list_a *tail);


#endif