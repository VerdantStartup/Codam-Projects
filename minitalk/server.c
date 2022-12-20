/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:34:20 by verdant           #+#    #+#             */
/*   Updated: 2022/12/20 12:40:44 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"
#include <limits.h>

void	ft_putchar_fd(char c, int fd) // delete when I have ft_printf implemented
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd) // delete when I have ft_printf implemented
{
	if (n < 10 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	else if (n > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
}

void	handler(int signum) // I don't understand c = c << 1 & c += signum == SIGUSR1
{
	static int	i;
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
	int pid; 
	
	argv[0] = NULL;
	if (argc > 1)
	{
		printf("Wrong input\tTry the following: <./server>"); // Use ft_printf later
		exit(1);
	}
	pid = getpid();
	ft_putnbr_fd(pid, 1); // exchange for ft_printf
	ft_putchar_fd('\n', 1); // exchange for ft_printf
	while(argc == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause (); 
	}
}