/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:08:04 by verdant           #+#    #+#             */
/*   Updated: 2023/01/07 19:27:54 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft_with_all/include/libft.h"
# include "../libft_with_all/include/ft_printf.h"
# include "../libft_with_all/include/get_next_line.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/MLX42/include/MLX42/MLX42_Input.h"
# include "../lib/MLX42/include/MLX42/MLX42_Int.h"
# include <CoreGraphics/CoreGraphics.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>

#define BPP sizeof(int32_t)

typedef struct point
{
	float		x;
	float		y;
	float		z;
	float		x_iso;
	float		y_iso;
	int			color; // Implemented after mandatory part
} t_point;

typedef struct data
{
	double	angle;
	int			max_pts;
	int			zoom;
	int			z_zoom;
	int			width;
	int			height;
	int			x_Offset;
	int			y_Offset;
	// int			padding;
	int			x_max;
	int			y_max;
} t_data;

typedef struct draw_setup
{
	int					dx;
	int					dy;
	int					error;
	int					x_step;
	int					y_step;
	int					x0;
	int					x1;
	int					y0;
	int					y1;
	mlx_t				*mlx;
	mlx_image_t	*img;
} t_helper;


/*			Utils			*/
int			get_max_points(const char *filename, t_data **data);
void		calc_offsets(t_point *pts, t_data **data);
void		free_split(char **line);
void		mlx_setup(t_helper	*setup, t_data **data);
void		cleaning_draw(t_helper *setup);

/*			Error Handling			*/
void		check_map(char *line, int x_cnt);
void		ft_iserror(char *msg);

/*			Parsing			*/
int			get_max_points(const char *filename, t_data **data);
t_point	*parse_map(const char *filename, t_point *pts, t_data **data);

/*			Drawing			*/
t_point	*cvt_iso(t_point *pts, t_data **data);
void		*draw_init(t_helper *setup, t_point *p0,t_point *p1);
void		draw_line(t_point *p0, t_point *p1, t_helper *setup);
void		create_projection(t_point *pts, t_data **data);


#endif