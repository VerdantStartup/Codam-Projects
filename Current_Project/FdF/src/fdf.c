/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:51:07 by verdant           #+#    #+#             */
/*   Updated: 2023/01/07 20:30:08 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Add to main if you wanna check leaks
// atexit(leaks);
// void	leaks(void)
// {
// 	system("leaks -q FdF");
// }

void	set_data(t_data **data, const char *filename)
{
	(*data)->max_pts = (get_max_points(filename, data));
	if ((*data)->max_pts < 4)
		ft_iserror("Smaller than 4");
	(*data)->angle = 30 * (M_PI / 180);
	(*data)->zoom = 20;
	(*data)->z_zoom = 3;
	// (*data)->padding = 100;
}


int	main(int argc, char *argv[])
{
	const char	*filename = argv[1];
	t_point			*points;
	t_data			*data;

	// check_values(filename);
	if (!(data = ft_calloc(1, sizeof(t_data))))
		ft_iserror("Data ptr failed");
	if (argc != 2 || open(filename, O_RDONLY) < 0)
		ft_iserror("Wrong Inputs");
	set_data(&data, filename);
	points = parse_map(filename, points, &data);
	create_projection(points, &data);
	return (free(points), free(data), EXIT_SUCCESS);
}

