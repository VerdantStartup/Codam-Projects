/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:12:23 by verdant           #+#    #+#             */
/*   Updated: 2023/01/07 20:01:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// If z is non-numeric (Not implemneted)


// bool	check_chars(char	c)
// {
// 	if (c != ' ' && c != '\n')
// 		return (false);
// 	return (true);
// }

// void	check_values(char *filename)
// {
// 	const int	fd = open(filename, O_RDONLY);
// 	int	i = 0;
// 	char *line;

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		while(line[i])
// 		{
// 			if (!check_chars(line[i]) && !ft_isdigit(line[i]))
// 				ft_iserror("Incorrect Map");
// 			i++;
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }


void	check_map(char *line, int x_cnt)
{
	int				i;
	int				cnt;
	const	int	size = ft_strlen(line) - 1;
	char			**line2 = ft_split(line, ' ');

	i = 0;
	cnt = 0;
	while (line2[i])
		i++;
	if (i != x_cnt)
		ft_iserror("Numbers are missing");
	if (line[size] == '\n')
	{
		if (ft_isdigit(line[size - 1]))
			return (free_split(line2));
	}
	else
	{
		if (ft_isdigit(line[size]))
			return (free_split(line2));
	}
	ft_iserror("Check for spaces at the end of the line");
}

void	ft_iserror(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}
