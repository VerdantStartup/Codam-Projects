/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:20:36 by verdant           #+#    #+#             */
/*   Updated: 2023/01/02 15:07:08 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_max_points(const char *filename)
{
	char	*y_line;
	char	**x_line;
	int		y_cnt;
	int		x_cnt;
	const	int fd = open(filename, O_RDONLY);

	y_line = get_next_line(fd);
	y_cnt = 0;
	while (y_line)
	{
		if (y_cnt == 0)
		{
			x_cnt = 0;
			x_line = ft_split(y_line, ' ');
			while (x_line[x_cnt] != NULL)
				x_cnt++;
		}
		free(y_line);
		y_line = get_next_line(fd);
		y_cnt++;
	}
	close(fd);
	return (free(y_line), x_cnt * y_cnt);
}

t_point *read_values(t_point *points, char *y_line, int y, t_data **data)
{
	char	**x_line = ft_split(y_line, ' ');
	int					x;
	static int	num_points;

	x = 0;
	while (x_line[x])
	{
		points[num_points].x = x;
		points[num_points].y = y;
		points[num_points].z = ft_atoi(x_line[y]);
		points[num_points].color = false;
		num_points++;
		x++;
		(*data)->line_max = x;
	}
	points[num_points - 1].is_last = true;
	return (points);
}

t_point	*parse_map(const char *filename, t_point *pts, int max_pts, t_data **data)
{
	const	int	fd					=	open(filename, O_RDONLY);
	char			*y_line;
	int				y;
	
	pts = malloc(sizeof(t_point) * max_pts - 1);
	y = 0;
	y_line = get_next_line(fd);
	while (y_line)
	{
		pts = read_values(pts, y_line, y, data);
		y++;
		free(y_line);
		y_line = get_next_line(fd);
	}
	return (pts);
}







// void	parse_map(const char *filename, t_point *points)
// {
// 	const	int fd					=	open(filename, O_RDONLY);
// 	const	int	max_points	=	get_max_points(fd);
// 	char			*y_line;
// 	int				x;
	
// 	points = malloc(sizeof(t_point) * max_points);
// 	x = 0;
// 	while (y_line = get_next_line(fd))
// 	{
// 		points = read_y(points, y_line, x);
// 		x++;
// 		free(y_line);
// 		if (x = 1)
// 			break;
// 	}
// 	printf("%d", points[0].x)
// 	// printf("Func: %d Real Max_Points: 15 ", max_points);
// 	return ;
// }