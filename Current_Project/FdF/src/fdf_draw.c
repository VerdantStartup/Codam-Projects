/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:50:25 by verdant           #+#    #+#             */
/*   Updated: 2023/01/02 22:34:38 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>


void	draw_line(int x0, int y0, int x1, int y1, mlx_image_t *img, t_data **data)
{
	
	int addon_x;
	int addon_y;

	
	addon_x = (1440 - 100) / ((*data)->max_pts_x - 1);
	addon_y = (900 - 100) / ((*data)->max_pts_y - 1);

	// printf("x0 %d x1 %d\t", x0, x1);
	
	// x0 *= addon_x;
	// x1 *= addon_x;
	// y0 *= addon_y;
	// y1 *= addon_y;
	x0 *= 50;
	x1 *= 50;
	y0 *= 50;
	y1 *= 50;
	
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
		mlx_put_pixel(img, current_x + 200, current_y + 200, 0);
	}
}

t_point	*isometric(t_point *pts, t_data **data)
{
    int x;
    int y;
		int z;
		int cnt;

   
		cnt = 0;
		while (cnt <= (*data)->max_pts)
		{
			x = pts[cnt].x;
   		y = pts[cnt].y;
			z = pts[cnt].z;
			// printf("At cnt: |%d|\tx_iso: |%f|\ty_iso: |%f|\n", cnt,pts[cnt].x, pts[cnt].y);
			pts[cnt].x = x - y;
			pts[cnt].y = (x + y) / 2 - z;
			printf("At cnt: |%d|\tx_iso: |%f|\ty_iso: |%f|\n", cnt,pts[cnt].x, pts[cnt].y);
			cnt++;
		}
		return (pts);
}


void create_projection(t_point *pts, t_data **data)
{
	int x, y, x1, y1, i, ends;

	ends = (*data)->line_max;
	i = 0;
	mlx_t	*mlx = mlx_init(2560, 1600, "Test", true);
	if (!mlx)
		ft_error("mlx ptr broken");
	mlx_image_t *img = mlx_new_image(mlx, 1440, 900);
	if (!img)
		ft_error("img ptr broken");
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);
	pts = isometric(pts, data);
	while (i <= (*data)->max_pts)
	{
		if (pts[i].x > 0)
		draw_line(pts[i].x - 1, pts[i].y, pts[i].x, pts[i].y, img, data);
	 if (pts[i].y > 0)
		 draw_line(pts[i].x, pts[i].y - 1, pts[i].x, pts[i].y, img, data);
		i++;
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}


