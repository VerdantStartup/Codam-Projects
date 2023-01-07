#include <CoreGraphics/CoreGraphics.h>
#include <stdio.h>



	while (i < (*data)->max_pts)
	{
		if (((i + 1) % temp->x_max) != 0 || i == 0)
			draw_line(pts[i].x_iso, pts[i].y_iso, pts[i + 1].x_iso, pts[i + 1].y_iso, img);
		i++;
	}
	
	while (i < (temp->max_pts - temp->x_max))
	{
		draw_line(pts[i].x_iso, pts[i].y_iso, pts[i + temp->x_max].x_iso, pts[i + temp->x_max].y_iso, img);
		i++;
	}









// void	draw_line(int x0, int y0, int x1, int y1, mlx_image_t *img)
// {
// 	int	dx = abs(x1 - x0);
// 	int	dy = -abs(y1 - y0);
// 	int	x_step;
// 	int	y_step;
// 	int	error;
// 	int	current_x = x0;
// 	int	current_y = y0;
// 	int e2;

// 	error = dx + dy;
// 	x_step = (x0 < x1) ? 1 : -1;
// 	y_step = (y0 < y1) ? 1 : -1;
// 	while (current_x != x1 || current_y != y1)
// 	{
// 		e2 = 2 * error;
// 		if (e2 >= dy)
// 		{
// 			current_x += x_step;
// 			error += dy;
// 		}
// 		if (e2 <= dx)
// 		{
// 			current_y += y_step;
// 			error += dx;
// 		}
// 		mlx_put_pixel(img, current_x, current_y, 255);
// 	}
// }