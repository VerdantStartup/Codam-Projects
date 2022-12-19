/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:45:01 by verdant           #+#    #+#             */
/*   Updated: 2022/12/19 11:05:21 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;
	int	bits[8];

	i = 0;
	while (i != 8)
	{
		bits[i] = ((c >> i) & 1);
		i++;
	}
	while (i > 0)
	{
		i--;
		if (bits[i] == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else if (bits[i] == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(200);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;
	
	i = 0;
	if (argc < 3)
	{
		printf("Wrong input\tTry the following: ./client <pid> <input string>"); // Change to ft_printf later
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	while(i < ft_strlen(argv[2]))
	{
		send_char(pid , argv[2][i]);
		i++;
	}
	send_char(pid , '\0');
}

