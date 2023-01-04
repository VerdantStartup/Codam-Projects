/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:20:36 by verdant           #+#    #+#             */
/*   Updated: 2023/01/04 21:17:07 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// implement that the lost space in the first line doesnt get counted

t_point *read_values(t_point *points, char *y_line, int y, t_data **data)
{
	char		**x_line = ft_split(y_line, ' ');
	int			x;
	static int	num_points;

	x = 0;
	while (x_line[x])
	{
		points[num_points].x = x;
		points[num_points].y = y;
		points[num_points].z = ft_atoi(x_line[y]);
		num_points++;
		x++;
	}
	return (points);
}

t_point	*parse_map(const char *filename, t_point *pts, t_data **data)
{
	const int	fd = open(filename, O_RDONLY);
	char		*y_line;
	int			y;
	
	pts = malloc(sizeof(t_point) * (*data)->max_pts - 1);
	y = 0;
	y_line = get_next_line(fd);
	while (y_line)
	{
		pts = read_values(pts, y_line, y, data);
		y++;
		free(y_line);
		y_line = get_next_line(fd);
	}
	close(fd);
	return (pts);
}
