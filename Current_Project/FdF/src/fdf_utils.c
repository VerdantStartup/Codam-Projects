/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:28:29 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/07 19:35:45 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_max_points(const char *filename, t_data **data)
{
	char		*y_row;
	char		**x_col;
	int			y_cnt;
	int			x_cnt;
	const int	fd = open(filename, O_RDONLY);
	
	if (!fd)
		ft_iserror("open failed");
	y_cnt = 0;
	x_cnt = 0;
	y_row = get_next_line(fd);
	x_col = ft_split(y_row, ' ');
	while (x_col[x_cnt] && x_col[x_cnt][0] != '\n')
		x_cnt++;
	while (y_row)
	{
		check_map(y_row, x_cnt);
		free(y_row);
		y_row = get_next_line(fd);
		y_cnt++;
	}
	close(fd);
	(*data)->x_max = x_cnt;
	(*data)->y_max = y_cnt;
	free_split(x_col);
	return (free(y_row), x_cnt * y_cnt); 
}

void	free_split(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void	mlx_setup(t_helper	*setup, t_data **data)
{
	mlx_t				*mlx;
	mlx_image_t	*img;
	t_data			*temp;

	temp = (*data);
	mlx = mlx_init(temp->width, temp->height, "FdF", true);
	if (!mlx)
		ft_iserror("mlx ptr failed");
	img = mlx_new_image(mlx, temp->width, temp->height);
	if (!img)
		ft_iserror("img ptr failed");
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);
	setup->mlx = mlx;
	setup->img = img;
}

void	cleaning_draw(t_helper *setup)
{
	mlx_delete_image(setup->mlx, setup->img);
	mlx_terminate(setup->mlx);
	free(setup);
}
