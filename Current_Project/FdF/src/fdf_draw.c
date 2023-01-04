/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:50:25 by verdant           #+#    #+#             */
/*   Updated: 2023/01/04 21:21:34 by mwilsch          ###   ########.fr       */
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
	while (cnt < temp->max_pts)
	{
		x_prev = pts[cnt].x * (temp->zoom);
		y_prev = pts[cnt].y * (temp->zoom);
		// Transform x & y value to 2D isometric values
		pts[cnt].x_iso = (x_prev - y_prev) * cos(temp->angle);
		pts[cnt].y_iso = -(pts[cnt].z) + (x_prev - y_prev) * sin(temp->angle);
		pts[cnt].x_iso += 1000;
		pts[cnt].y_iso += 1000;
		cnt++;
	}
	return (pts);
}


// My new draw_line function
void	draw_line(int x1, int y1, int x2, int y2, mlx_image_t *img)
{
	int			temp;
	
	float		m;
	float		x, y;
	
	const int	dx = x2 - x1;
	const int	dy = y2 - y1;
	
	if (abs(dx) > abs(dy))
	{
		x = (int)x;
		if (x1 > x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		m = (float)dy / (float)dx;
		y = y1;
		for (x = x1; (int)x <= x2; x++)
		{
			mlx_put_pixel(img, x, round(y), 255);
			y += m;
		}
	}
	else
	{
		y = (int)y;
		if (y1 > y2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		m = (float)dx / (float)dy;
		x = x1;
		for (y = y1; y <= y2; y++)
		{
			mlx_put_pixel(img, round(x), y, 255);
			x += m;
		}
	}
}

// My old draw_line function
void	draw_line(int x0, int y0, int x1, int y1, mlx_image_t *img)
{

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
		mlx_put_pixel(img, current_x, current_y, 255);
	}
}

void create_projection(t_point *pts, t_data **data)
{
	int	i;
	
	i = 0;

// Intilaised MLX and Image | (Copy over to set data later)
	mlx_t *mlx = mlx_init(2000, 1500, "Test", true);
	if (!mlx)
		ft_error("mlx ptr failed");
	mlx_image_t *img = mlx_new_image(mlx, 2000, 1500);
	if (!img)
		ft_error("Img ptr failed");
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);

	
// Isometric Projection
	pts = cvt_iso(pts, data);
	


// Drawing the line
	// ???

// Loop & Cleaning
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}


