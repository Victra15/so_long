/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_cntl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:45:28 by yolee             #+#    #+#             */
/*   Updated: 2022/06/29 15:10:56 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx_data(t_data *mlx_data)
{
	mlx_data = (t_data *)safe_malloc(sizeof(t_data));
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, 1920, 1080, "so_long");
	mlx_data->img = (t_img *)safe_malloc(sizeof(t_img));
	mlx_data->img->img = mlx_get_data_addr(mlx_data->mlx,
			mlx_data->img->bits_per_pixel,
			mlx_data->img->line_length,
			mlx_data->img->endian);
}

void	destroy_mlx_data(t_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img->img);
	safe_free(&mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	safe_free(&mlx_data->mlx);
	safe_free(&mlx_data);
}
