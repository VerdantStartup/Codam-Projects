/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:34:20 by verdant           #+#    #+#             */
/*   Updated: 2022/12/22 14:11:16 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum) // I don't understand c = c << 1 & c += signum == SIGUSR1
{
	static int						i;
	static unsigned char	c;

	c = c << 1;
	if (signum == SIGUSR1)
		c += 1;
	else if (signum == SIGUSR2)
		c += 0;
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int main(int argc, char *argv[])
{
	int	pid;
	
	argv[0] = NULL;
	if (argc > 1)
	{
		ft_printf("Wrong input\tTry the following: <./server>");
		exit(1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while(argc == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause (); 
	}
}