/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:51:07 by verdant           #+#    #+#             */
/*   Updated: 2023/01/05 21:36:21 by mwilsch          ###   ########.fr       */
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

int	get_max_points(const char *filename, t_data **data)
{
	char	*y_line;
	char	**x_line;
	int		y_cnt;
	int		x_cnt;
	const	int fd = open(filename, O_RDONLY);
	if (!fd)
	{
		ft_error("open failed");
		return (-1);
	}
	y_cnt = 0;
	x_cnt = 0;
	y_line = get_next_line(fd);
	x_line = ft_split(y_line, ' ');
	while (x_line[x_cnt])
		x_cnt++;
	while (y_line)
	{
		if (y_cnt == 0)
		free(y_line);
		y_line = get_next_line(fd);
		y_cnt++;
	}
	close(fd);
	free(y_line);
	return (x_cnt * y_cnt); 
}

void	set_data(t_data **data, const char *filename)
{
	(*data)->angle = 30 * (M_PI / 180);
	(*data)->max_pts = (get_max_points(filename, data));
	(*data)->zoom = 20;
	(*data)->x_Offset = 1000 / 2;
	(*data)->y_Offset = 1000 / 2;
	(*data)->x_max = 19;
}


int	main(int argc, char *argv[])
{
	const char	*filename = argv[1];
	t_point		*points;
	t_data		*data = NULL;

	if (!(data = malloc(1 * sizeof(t_data))))
		ft_error("Data ptr failed");
	if (argc != 2 || open(filename, O_RDONLY) < 0)
		exit(1);
	set_data(&data, filename);
	points = parse_map(filename, points, &data);
	for (int i = 0; i <= data->max_pts; i++)
		printf("At %d\tz:%f\n", i, points[i].z);

	
		
	create_projection(points, &data);
	
}
