/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:14:57 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/03 15:47:32 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
// # include <stdio.h> // Delete this when done

/*			Stacks			*/
typedef struct stack
{
	struct stack	*prev;
	int				data;
	int				sim_num;
	struct stack	*next;
}	t_list;

/*			Utilities			*/
long int		ft_atoi(const char *str);
bool			is_sorted(t_list **stack_a, int size);
int				lst_size(t_list **tail);

/*			Error Handling			*/
bool			check_dups(char **argv, int argc);
bool			ft_isdigit(char **argv, int argc);
int				ft_strcmp(const char *s1, const char *s2);

/*			Parsing Data			*/
bool			add_end(t_list **head, int data);
bool			create_list(t_list **head, char **argv, int argc);

/*			Operations			*/
void			swap(t_list **tail, char c);
void			rotate(t_list **tail, char c);
void			reverse_rotate(t_list **tail, char c);
void			push(t_list **tail_take, t_list **tail_put, char c);

/*			Sorting			*/
void			sort_upto_5(t_list **stack_a, t_list **stack_b, int size);
void			sort3(t_list **tail, int size);
void			sort_big(t_list **stack_a, t_list **stack_b, int size);

#endif
