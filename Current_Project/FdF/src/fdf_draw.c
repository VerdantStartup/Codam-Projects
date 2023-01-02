/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:50:25 by verdant           #+#    #+#             */
/*   Updated: 2023/01/02 15:24:49 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>
// Sin() and Cos() is using radians not degrees
// Default angel is 30 degrees --> 0.5235987755982988 radians

void	draw_line(int x0, int y0, int x1, int y1, mlx_image_t *img)
{
	x0 *= 100;
	x1 *= 100;
	y0 *= 100;
	y1 *= 100;
	
	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	x_step;
	int	y_step;
	int	error;
	int	current_x = x0;
	int	current_y = y0;


	if (dx >= 0)
		x_step = 1;
	else
		x_step = -1;

	if (dy >= 0)
		y_step = 1;
	else
		y_step = -1;

	while (current_x != x1 || current_y != y1)
	{
		if (dx > dy)
		{
			current_x += x_step;
			error += dy;
		}
		else
		{
			current_y += y_step;
			error += dx;
		}
		mlx_put_pixel(img, current_x, current_y, 0);
	}
}


void create_projection(t_point *pts, int max_pts, t_data **data)
{
	int x0, y0, x1, y1, num_pts, ends;
	int xOffset = (1600 - 3) / 2;
	int yOffset = (2560 - 3) / 2;


	ends = (*data)->line_max;
	num_pts = 0;
	mlx_t	*mlx = mlx_init(1600, 2560, "Test", true);
	if (!mlx)
		ft_error("mlx ptr broken");
	mlx_image_t *img = mlx_new_image(mlx, 1600, 2560);
	if (!img)
		ft_error("img ptr broken");
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);




	// Create a line for each pair
	while (num_pts <= max_pts)
	{
		x0 = pts[num_pts].x;
		y0 = pts[num_pts].y;
		printf("At %d\tx: %d\ty: %d bool:%d\n",num_pts, x0, y0, pts[num_pts].is_last);
		num_pts++;
	}
	num_pts = 0;
	while (num_pts <= max_pts)
	{
		x0 = (pts[num_pts].x) + xOffset;
		y0 = (pts[num_pts].y) + yOffset;
		x1 = (pts[num_pts + 1].x) + xOffset;
		y1 = (pts[num_pts + 1].y) + yOffset;
		if (pts[num_pts].is_last == false)
		{
			// Draw horizontal lines
			draw_line(x0, y0, x1, y1, img);
			// Draw vertical lines
			draw_line(x0, y0, x1 - 1, y1 + 1, img);
		}
		else if (pts[num_pts].is_last == 1)
		{
			draw_line(x0, y0, x0 + 1, y0, img);
			draw_line(x0, y0, x0, y0 + 1, img);
		}
		draw_line(0, ends, ends, ends, img);
		draw_line(ends, 0, ends, ends, img);
		num_pts++;
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}


