/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:45:01 by verdant           #+#    #+#             */
/*   Updated: 2022/12/17 16:20:09 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include <limits.h>

// The thing which I am stuck on right now is that I don't understand how you can send a bit with signals
// I do understand how to encode a char into bits but how do you send it?

// What do I know?
	// I know that I will recieve a string which I need to print out in my server
	// I will print the string char by char
	// I will push a char of the string to my send function
	// The send function will send the each bit of the char until the char 8 bits have been send
	// When 8 bits have been send the char can be written
	// We loop until the while loop breaks in main
	
// What I don't know?
	// I don't know how to send one bit?
		// With the kill func?
	// I don't know how we recieve the bit?

// Sender
	// We use SIGUSR1 for 1 and SIGUSR2 for 0
	// Then we use kill(pid, SIGUSR1) to send the 1 and kill(pid, SIGUSR2) to send the 0

// How does SIGUSR1 take the bit?

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (res == 0)
		return (0);
	return (res * sign);
}


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
			kill(pid, SIGUSR1); 
		else if (bits[i] == 0)
			kill(pid, SIGUSR2);
		printf("%d", bits[i]);
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
	while(i < 1) // argv[2][i] != '\0'
	{
		send_char(pid , argv[2][i]);
		i++;
	}
}

