/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:50:25 by verdant           #+#    #+#             */
/*   Updated: 2023/01/07 14:11:36 by mwilsch          ###   ########.fr       */
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
	int	z;

	cnt = 0;
	temp = (*data);
	while (cnt < temp->max_pts)
	{
		// Multiplying the the zoom
		x_prev = pts[cnt].x * (temp->zoom);
		y_prev = pts[cnt].y * (temp->zoom);
		z = pts[cnt].z *(temp->z_zoom); // I want this to be changeable
		// // Transform x & y value to 2D isometric values
		pts[cnt].x_iso = (x_prev - y_prev) * cos(temp->angle);
		pts[cnt].y_iso = -z + (x_prev + y_prev) * sin(temp->angle);
		// // Adding the Offset
		pts[cnt].x_iso += temp->x_Offset;
		pts[cnt].y_iso += temp->y_Offset;
		// Add zoom and offset to non iso
			// pts[cnt].x *= (temp->zoom);
			// pts[cnt].y *= (temp->zoom);
			// pts[cnt].x += temp->x_Offset;
			// pts[cnt].y += temp->y_Offset;
		cnt++;
	}
	return (pts);
}

void	draw_line(int x0, int y0, int x1, int y1, mlx_image_t *img)
{

	t_helper	*draw_vars;

	draw_vars = draw_init(draw_vars);
	
	int	dx = abs(x1 - x0);
	int	dy = -abs(y1 - y0);
	int	x_step;
	int	y_step;
	int	error;
	int	current_x = x0;
	int	current_y = y0;
	int e2;

	error = dx + dy;
	x_step = (x0 < x1) ? 1 : -1;
	y_step = (y0 < y1) ? 1 : -1;
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
	int		i;
	const	t_data *temp = (*data);
	
	i = 0;
// Intilaised MLX and Image | (Copy over to set data later)
	mlx_t *mlx = mlx_init(temp->width, temp->height, "Test", true);
	if (!mlx)
		ft_iserror("mlx ptr failed");
	mlx_image_t *img = mlx_new_image(mlx, temp->width, temp->height);
	if (!img)
		ft_iserror("Img ptr failed");
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t)); // change this to ft_memset
	mlx_image_to_window(mlx, img, 0, 0);
// Isometric Projection
	pts = cvt_iso(pts, data);
// Horizontal lines
	// while (i < (*data)->max_pts)
	// {
	// 	if (((i + 1) % temp->x_max) != 0 || i == 0)
	// 		draw_line(pts[i].x_iso, pts[i].y_iso, pts[i + 1].x_iso, pts[i + 1].y_iso, img);
	// 	i++;
	// }
	// while (i < (*data)->max_pts)
	// {
	// 	if (((i + 1) % temp->x_max) != 0 || i == 0)
	// 		draw_line(pts[i], pts[i + 1], img);
	// 	i++;
	// }
// Vertical lines
	i = 0;
	while (i < (temp->max_pts - temp->x_max))
	{
		draw_line(pts[i].x_iso, pts[i].y_iso, pts[i + temp->x_max].x_iso, pts[i + temp->x_max].y_iso, img);
		i++;
	}
// Loop & Cleaning
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}


