/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:50:25 by verdant           #+#    #+#             */
/*   Updated: 2023/01/07 19:28:12 by mwilsch          ###   ########.fr       */
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

void *draw_init(t_helper *setup, t_point *p0,t_point *p1)
{
	setup->x0 = p0->x_iso;
	setup->y0 = p0->y_iso;
	setup->x1 = p1->x_iso;
	setup->y1 = p1->y_iso;

	setup->dx = abs(setup->x1 - setup->x0);
	setup->dy = -abs(setup->y1 - setup->y0);
	setup->error = (setup->dx + setup->dy);
	setup->x_step = (setup->x0 < setup->x1) ? 1 : -1;
	setup->y_step = (setup->y0 < setup->y1) ? 1 : -1;
	return (setup);
}

	// printf("%d %d %d %d", setup->x0, setup->y0, setup->x1, setup->y1);

void	draw_line(t_point *p0, t_point *p1, t_helper *setup)
{
	int				current_x;
	int				current_y;
	int				e2;

	setup = draw_init(setup, p0, p1);
	current_x = setup->x0;
	current_y = setup->y0;
	while (current_x != setup->x1 || current_y != setup->y1)
	{
		e2 = 2 * setup->error;
		if (e2 >= setup->dy)
		{
			current_x += setup->x_step;
			setup->error += setup->dy;
		}
		if (e2 <= setup->dx)
		{
			current_y += setup->y_step;
			setup->error += setup->dx;
		}
		mlx_put_pixel(setup->img, current_x, current_y, 255);
	}
}

void create_projection(t_point *pts, t_data **data)
{
	t_helper		*setup;
	int					i;
	const	t_data *temp = (*data);

	setup = ft_calloc(1, sizeof(t_helper));
	if (!setup)
		ft_iserror("Setup ptr failed");
	i = 0;
	mlx_setup(setup, data);
	pts = cvt_iso(pts, data);
	while (i < (*data)->max_pts)
	{
		if (((i + 1) % temp->x_max) != 0 || i == 0)
			draw_line(&pts[i], &pts[i + 1], setup);
		i++;
	}
	i = 0;
	while (i < (temp->max_pts - temp->x_max))
	{
		draw_line(&pts[i], &pts[i + temp->x_max], setup);
		i++;
	}
	mlx_loop(setup->mlx);
	cleaning_draw(setup);;
}

// void create_projection(t_point *pts, t_data **data)
// {
// 	int		i;
// 	const	t_data *temp = (*data);
// 	t_helper *setup;

// 	setup = ft_calloc(1, sizeof(t_helper));
// 	if (!setup)
// 		ft_iserror("Setup ptr failed");
// 	i = 0;
// // Intilaised MLX and Image | (Copy over to set data later)
// 	mlx_setup(setup, data);
// // Isometric Projection
// 	pts = cvt_iso(pts, data);

// // Horizontal lines
// 	while (i < (*data)->max_pts)
// 	{
// 		if (((i + 1) % temp->x_max) != 0 || i == 0)
// 			draw_line(&pts[i], &pts[i + 1], setup);
// 		i++;
// 	}
// // Vertical lines
// 	i = 0;
// 	while (i < (temp->max_pts - temp->x_max))
// 	{
// 		draw_line(&pts[i], &pts[i + temp->x_max], setup);
// 		i++;
// 	}
// // Loop & Cleaning
// 	mlx_loop(setup->mlx);
// 	mlx_delete_image(setup->mlx, setup->img);
// 	mlx_terminate(setup->mlx);
// 	free(setup);
// }

// 	mlx_t *mlx = mlx_init(temp->width, temp->height, "Test", true);
// 	if (!mlx)
// 		ft_iserror("mlx ptr failed");
// 	mlx_image_t *img = mlx_new_image(mlx, temp->width, temp->height);
// 	if (!img)
// 		ft_iserror("Img ptr failed");
// 	setup->img = img;
// 	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t)); // change this to ft_memset
// 	mlx_image_to_window(mlx, img, 0, 0);



