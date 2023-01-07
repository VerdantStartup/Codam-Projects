/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:51:07 by verdant           #+#    #+#             */
/*   Updated: 2023/01/07 13:55:45 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

int	get_max_points(const char *filename, t_data **data)
{
	char		*y_row;
	char		**x_col;
	int			y_cnt;
	int			x_cnt;
	const int	fd = open(filename, O_RDONLY);
	
	if (!fd)
		ft_iserror("open failed");
	y_cnt = 0;
	x_cnt = 0;
	y_row = get_next_line(fd);
	x_col = ft_split(y_row, ' ');
	while (x_col[x_cnt] && x_col[x_cnt][0] != '\n')
		x_cnt++;
	while (y_row)
	{
		check_map(y_row, x_cnt);
		free(y_row);
		y_row = get_next_line(fd);
		y_cnt++;
	}
	close(fd);
	(*data)->x_max = x_cnt;
	(*data)->y_max = y_cnt;
	return (free(y_row), x_cnt * y_cnt); 
}

void	set_data(t_data **data, const char *filename)
{
	(*data)->max_pts = (get_max_points(filename, data));
	if ((*data)->max_pts < 4)
		ft_iserror("Smaller than 4");
	(*data)->angle = 30 * (M_PI / 180);
	(*data)->angle_60 = 90 * (M_PI / 180);
	(*data)->zoom = 5;
	(*data)->z_zoom = 2;
	// (*data)->padding = 100;
}


int	main(int argc, char *argv[])
{
	const char	*filename = argv[1];
	t_point		*points;
	t_data		*data = NULL;

	if (!(data = malloc(1 * sizeof(t_data))))
		ft_iserror("Data ptr failed");
	if (argc != 2 || open(filename, O_RDONLY) < 0)
		ft_iserror("Wrong Inputs");
	set_data(&data, filename);
	points = parse_map(filename, points, &data);
	create_projection(points, &data);
}

