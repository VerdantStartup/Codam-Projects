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

// x_offset is the width - x_new + the most left points to to center it
// y_offset is the height - y_new + z value

void	calc_offsets(t_point *pts,t_data **data)
{
	t_data	*t_d;
	int			dimensions;
	float		x_new;
	float		y_new;
	
	t_d = (*data);
	dimensions = (t_d->x_max - 1) + (t_d->y_max - 1);
	x_new = dimensions * t_d->zoom * cos(t_d->angle);
	y_new = dimensions * t_d->zoom * sin(t_d->angle);
	CGDirectDisplayID mainDisplay = CGMainDisplayID();
	CGRect screenRect = CGDisplayBounds(mainDisplay);
	t_d->width = screenRect.size.width;
	t_d->height = screenRect.size.height;
	t_d->x_Offset = (t_d->width - x_new) / 2 + ((t_d->y_max  - 1) * t_d->zoom * cos(t_d->angle));
	t_d->y_Offset = ((t_d->height - y_new) / 2) + (pts[0].z * t_d->z_zoom);
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
	x = 0;
	free_split(x_col);
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
	// // t_d->y_Offset = temp->height / 3;
	// printf("y_offset %d\n", temp->y_Offset);
	// // printf("y_new %f\n", y_new);
	// printf("x_max %d\n", temp->x_max - 1);
	// printf("y_max: %d\n", temp->y_max - 1);
	// printf("zoom: %d\n", temp->zoom);
	// printf("sin: %f\n", sin(temp->angle));