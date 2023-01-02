/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:51:07 by verdant           #+#    #+#             */
/*   Updated: 2023/01/02 15:18:01 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pseudocode
	// 1.	Error Handling	(Done)
	// 2.	Read the map		(Done)
	// 3.	Draw the line		()
		//	1. Calc x_iso & y_iso
		// 	2. Implement the draw_line function with the help 
		// of the Brensham Line Algo
		//	3. Use the MLX42 graphic lib functions to draw lines


#include "../include/fdf.h"

void	set_data(t_data **data, const char *filename)
{
	(*data)->angle = 30 * (M_PI / 180);
	(*data)->max_pts = (get_max_points(filename) - 1);
}

t_point	*isometric(t_point *pts, t_data **data)
{
	int	x_prev;
	int	y_prev;
	int	cnt;

	cnt = 0;
	while(cnt < (*data)->max_pts)
	{
		x_prev = pts[cnt].x;
		y_prev = pts[cnt].y;
		// printf("%f\t%f\n", pts[cnt].x, pts[cnt].y);
		pts[cnt].x = (x_prev - y_prev) * cos((*data)->angle);
		pts[cnt].y = (x_prev + y_prev) * sin((*data)->angle) - pts[cnt].z;
		printf("%f\t%f\n", pts[cnt].x, pts[cnt].y);
		cnt++;
	}
	return (pts);
}


int	main(int argc, char *argv[])
{
	const char	*filename = argv[1];
	int					max_points = (get_max_points(filename) - 1); // Delete later
	t_point			*points;
	t_data			*data = NULL;

	if (!(data = malloc(1 * sizeof(t_data))))
		ft_error("Data ptr broken");
	set_data(&data, filename);
	if (argc != 2 || open(filename, O_RDONLY) < 0)
		ft_error("Wrong Inputs");
	points = parse_map(filename, points, max_points, &data);
	// points = isometric(points, &data);
	create_projection(points, max_points, &data);
}
