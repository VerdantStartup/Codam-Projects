/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 09:08:04 by verdant           #+#    #+#             */
/*   Updated: 2023/01/02 22:38:57 by verdant          ###   ########.fr       */
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
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>

#define BPP sizeof(int32_t)

typedef struct point
{
	float		x;
	float		y;
	float			z;
	bool		is_last;
	int			color; // Implemented after mandatory part
} t_point;

typedef struct data
{
	int line_max;
	int	max_pts;
	double	angle;
	int max_pts_x;
	int max_pts_y;
} t_data;


/*			Error Handling			*/
void		ft_error(char *msg);

/*			Parsing			*/
t_point	*parse_map(const char *filename, t_point *pts, t_data **data);
int			get_max_points(const char *filename, t_data **data);

/*			Drawing			*/
void		create_projection(t_point *pts, t_data **data);

#endif