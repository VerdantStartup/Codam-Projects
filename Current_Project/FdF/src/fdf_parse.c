/* ************************************************************************** *//*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:20:36 by verdant           #+#    #+#             */
/*   Updated: 2023/01/06 20:02:11 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	calc_offsets(t_point *pts,t_data **data)
{
	t_data *temp;
	
	temp = (*data);
	CGDirectDisplayID mainDisplay = CGMainDisplayID();
	CGRect screenRect = CGDisplayBounds(mainDisplay);

	temp->width = screenRect.size.width;
	temp->height = screenRect.size.height;
	
 // With the help off (insert name here) we centered it on the y_axis and y_axis
	float x_new = (((temp->x_max - 1) + ((temp->y_max - 1))) * temp->zoom) * cos(temp->angle);
	float y_new = (((temp->x_max - 1) + (temp->y_max - 1)) * temp->zoom) * sin(temp->angle);

	// x_offset is the width - x_new + the most left points to to center it
	temp->x_Offset = (temp->width - x_new) / 2 + ((temp->y_max  - 1) * temp->zoom * cos(temp->angle));
	// y_offset is the height - y_new + z value
	temp->y_Offset = ((temp->height - y_new) / 2) + (pts[0].z * temp->z_zoom);
}



t_point *read_values(t_point *pts, char *y_line, int y, t_data **data)
{
	char	**x_col = ft_split(y_line, ' ');
	int			x;
	static int	cnt;

	x = 0;
	while (x_col[x])
	{
		pts[cnt].x = x;
		pts[cnt].y = y;
		pts[cnt].z = ft_atoi(x_col[x]);
		cnt++;
		x++;
	}
	return (pts);
}

t_point	*parse_map(const char *filename, t_point *pts, t_data **data)
{
	const int	fd = open(filename, O_RDONLY);
	char		*y_line;
	int			y;
	
	pts = malloc(sizeof(t_point) * (*data)->max_pts);
	y = 0;
	y_line = get_next_line(fd);
	while (y_line)
	{
		pts = read_values(pts, y_line, y, data);
		y++;
		free(y_line);
		y_line = get_next_line(fd);
	}
	calc_offsets(pts, data);
	close(fd);
	return (pts);
}


// Data to print out
	// // temp->y_Offset = temp->height / 3;
	// printf("y_offset %d\n", temp->y_Offset);
	// // printf("y_new %f\n", y_new);
	// printf("x_max %d\n", temp->x_max - 1);
	// printf("y_max: %d\n", temp->y_max - 1);
	// printf("zoom: %d\n", temp->zoom);
	// printf("sin: %f\n", sin(temp->angle));