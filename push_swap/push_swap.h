/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:14:57 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/25 11:44:42 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>

/*			Stacks			*/

typedef struct s_list
{
	int			data;
	struct	s_list *next;
}	t_list_a;

/*			Error Handling			*/
bool	checkDups(char **argv, int argc);
bool	ft_isdigit(char **argv, int argc);
int		ft_strcmp(const char *s1, const char *s2);

/*			Parsing Data			*/
t_list_a	*firstNode(int data);
t_list_a	*addEnd(t_list_a *tail, int data);
t_list_a	*createList(t_list_a *tail, char **argv, int argc);


/*			Utilities			*/
int		ft_atoi(const char *str);



#endif