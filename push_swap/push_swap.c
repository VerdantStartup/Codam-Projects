/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/19 17:54:13 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>


//     return 0;
// }

// Error Handling
	// If a counter turns 2 then return "Error" on standard Error

// What does atoi return when the str[i] is not a digit

// find the biggest number
// malloc dups with size of biggest number
// dups[num]++
// if dups[num] == 2
// break;

int main(int argc, char *argv[])
{
	int	i;
	int	num;
	int	int_arr[argc];
	
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (argv[i][0] != '0' && num == 0) // Checking for non digit input
		{
			printf("Error -1");
			break;
		}
		int_arr[i] = num;
		// Check which sort_algo I wanna use before I parse the data 
		// continue with Miro Flowcharts before writing more code
		i++;
	}
}
