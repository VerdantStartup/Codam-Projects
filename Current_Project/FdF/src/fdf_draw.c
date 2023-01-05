/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:50:25 by verdant           #+#    #+#             */
/*   Updated: 2023/01/05 18:43:27 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

t_point	*cvt_iso(t_point *pts, t_data **data)
{
	int	cnt;
	t_data *temp;
	int	x_prev;
	int	y_prev;

	cnt = 0;
	temp = (*data);
	while (cnt <= temp->max_pts)
	{
		// Multiplying the the zoom
		x_prev = pts[cnt].x * (temp->zoom);
		y_prev = pts[cnt].y * (temp->zoom);
		// Transform x & y value to 2D isometric values
		pts[cnt].x_iso = (x_prev - y_prev) * cos(0.523599);
		pts[cnt].y_iso = -(pts[cnt].z) + (x_prev + y_prev) * sin(0.523599);
		// Adding the Offset
		pts[cnt].x_iso += 400;
		pts[cnt].y_iso += 400;
		// Trying non iso nums
		// pts[cnt].x *= (temp->zoom);
		// pts[cnt].y *= (temp->zoom);
		// pts[cnt].x += 500;
		// pts[cnt].y += 500;
		cnt++;
	}
	return (pts);
}

void	draw_line(int x0, int y0, int x1, int y1, mlx_image_t *img)
{

	int	dx = abs(x1 - x0);
	int	dy = -abs(y1 - y0);
	int	x_step;
	int	y_step;
	int	error;
	int	current_x = x0;
	int	current_y = y0;
	int e2;

	printf("%d\t", x0);

	error = dx + dy;
	if (x0 < x1)
		x_step = 1;
	else
		x_step = -1;
	if (y0 < y1)
		y_step = 1;
	else
		y_step = -1;

	while (current_x != x1 || current_y != y1)
	{
		e2 = 2 * error;
		if (e2 >= dy)
		{
			current_x += x_step;
			error += dy;
		}
		if (e2 <= dx)
		{
			current_y += y_step;
			error += dx;
		}
		mlx_put_pixel(img, current_x, current_y, 255);
	}
}

void create_projection(t_point *pts, t_data **data)
{
	int	i;
	
	i = 0;

// Intilaised MLX and Image | (Copy over to set data later)
	mlx_t *mlx = mlx_init(1000, 1000, "Test", true);
	if (!mlx)
		ft_error("mlx ptr failed");
	mlx_image_t *img = mlx_new_image(mlx, 1000, 1000);
	if (!img)
		ft_error("Img ptr failed");
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);

	
// Isometric Projection
	pts = cvt_iso(pts, data);
	


// Drawing the line
	// draw_line(100, 100, 200, 200, img);
	// draw_line(400, 400, 300, 300, img);
	// draw_line(300, 300, 300, 400, img);
	// draw_line(500, 500, 600, 500, img);

	// printf("%f %f %f %f", pts[0].x_iso, pts[0].y_iso, pts[1].x_iso, pts[1].y_iso);
	draw_line(pts[0].x_iso, pts[0].y_iso, pts[1].x_iso, pts[1].y_iso, img);
	draw_line(pts[0].x_iso, pts[0].y_iso, pts[3].x_iso, pts[3].y_iso, img);

	
	draw_line(pts[1].x_iso, pts[1].y_iso, pts[2].x_iso, pts[2].y_iso, img);
	draw_line(pts[1].x_iso, pts[1].y_iso, pts[4].x_iso, pts[4].y_iso, img);
	
	draw_line(pts[2].x_iso, pts[2].y_iso, pts[5].x_iso, pts[5].y_iso, img);
	
	draw_line(pts[3].x_iso, pts[3].y_iso, pts[4].x_iso, pts[4].y_iso, img);
	draw_line(pts[4].x_iso, pts[4].y_iso, pts[5].x_iso, pts[5].y_iso, img);

	draw_line(pts[3].x_iso, pts[3].y_iso, pts[6].x_iso, pts[6].y_iso, img);
	draw_line(pts[6].x_iso, pts[6].y_iso, pts[7].x_iso, pts[7].y_iso, img);
	
	draw_line(pts[4].x_iso, pts[4].y_iso, pts[7].x_iso, pts[7].y_iso, img);
	
	printf("%f %f", pts[7].x_iso, pts[5].y_iso);
	draw_line(pts[5].x_iso, pts[5].y_iso, pts[8].x_iso, pts[8].y_iso, img);
	draw_line(pts[7].x_iso, pts[7].y_iso, pts[8].x_iso, pts[8].y_iso, img);


	
	// draw_line(pts[0].x_iso, pts[0].y_iso, pts[3].x_iso, pts[3].y_iso);
	// draw_line(pts[1].x_iso, pts[1].y_iso, pts[3].x_iso, pts[3].y_iso);
	// draw_line(pts[2].x_iso, pts[2].y_iso, pts[5].x_iso, pts[5].y_iso);

	

// Loop & Cleaning
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}


