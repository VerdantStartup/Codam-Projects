/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:08:04 by verdant           #+#    #+#             */
/*   Updated: 2023/01/07 14:07:34 by mwilsch          ###   ########.fr       */
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
	float		x_iso;
	float		y;
	float		y_iso;
	float		z;
	// bool		is_last;
	int			color; // Implemented after mandatory part
} t_point;

typedef struct data
{
	double	angle;
	double	angle_60;
	int			max_pts;
	int			zoom;
	int			z_zoom;
	int			width;
	int			x_Offset;
	int			height;
	int			y_Offset;
	// int			padding;
	int			x_max;
	int			y_max;
} t_data;

typedef struct draw_setup
{
	int test;
} t_helper;


/*			Data			*/
void		calc_offsets(t_point *pts, t_data **data);

/*			Error Handling			*/
void		check_map(char *line, int x_cnt);
void		ft_iserror(char *msg);

/*			Parsing			*/
t_point	*parse_map(const char *filename, t_point *pts, t_data **data);
int			get_max_points(const char *filename, t_data **data);

/*			Drawing			*/
void		create_projection(t_point *pts, t_data **data);



#endif