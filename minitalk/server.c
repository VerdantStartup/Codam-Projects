/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:34:20 by verdant           #+#    #+#             */
/*   Updated: 2022/12/17 14:47:36 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"
#include <limits.h>


// void test(void)
// {
// 	char	c = 'a';
// 	int		bits[CHAR_BIT];
// 	int 	i = 0;

// 	while (i != 8)
// 	{
// 		bits[i] = ((c >> i) & 1);
// 		i++;
// 	}
// 	i = 0;
// 	while (i != 8)
// 	{
		
// 	}
// }



// void	handler(int signum)
// {
// 	static int i = 0;
// 	static unsigned char c = 0;

// 	c = c << 1;
// 	c += signum;
// 	if (++i == 8)
// 	{
// 		write (1, &c, 1);
// 		i = 0;
// 		c = 0;
// 	}
// 	// if (signum == SIGUSR1)
// 	// 	c += signum;
// 	// else
// 	// 	c+= signum;
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
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

void	handler(int signum)
{
	static int i;
	static int bits[8];
	// unsigned char c;

	i = 0;
	// c = 0;

	if (signum == SIGUSR1)
	{
		bits[i] = 1;
		write(1, "1", 1);
		i++;
	}
	else if (signum == SIGUSR2)
	{
		bits[i] = 0;
		write(1, "0", 1);
		i++;
	}
	sleep(1);
	// if (i == 8)
	// {
	// 	write(1, "test", 4);
	// 	// exit(1);
	// }

}


int main(int argc, char *argv[])
{
	int pid; 
	
	if (argc > 1)
	{
		printf("Wrong input\tTry the following: <./server>"); // Use ft_printf later
		exit(1);
	}
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);

	while(argc == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		sleep(1); 
	}
	// Implement infinite while loop 
		// Implement decoder in infinite while loop
	
}