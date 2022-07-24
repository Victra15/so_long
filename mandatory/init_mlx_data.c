/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:45:28 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 02:28:00 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx_data(t_mlx **mlx_data)
{
	(*mlx_data) = (t_mlx *)safe_malloc(sizeof(t_mlx));
	(*mlx_data)->mlx = mlx_init();
	(*mlx_data)->mlx_win = mlx_new_window((*mlx_data)->mlx,
			1280,
			1080,
			"so_long");
}

static void	init_img_data(t_mlx *mlx_data, t_img_data **img_data)
{
	(*img_data) = (t_img_data *)safe_malloc(sizeof(t_img_data));
	init_img(mlx_data->mlx, &(*img_data)->collect_img, "./res/collect.xpm");
	init_img(mlx_data->mlx, &(*img_data)->exit_img, "./res/exit.xpm");
	init_img(mlx_data->mlx, &(*img_data)->tile_img, "./res/tile.xpm");
	init_img(mlx_data->mlx, &(*img_data)->wall_img, "./res/wall.xpm");
}

static void	init_player(t_mlx *mlx_data, t_player **player)
{
	(*player) = (t_player *)safe_malloc(sizeof(t_player));
	init_img(mlx_data->mlx, &(*player)->character_img, "./res/hero.xpm");
	(*player)->player_pos.x = 0;
	(*player)->player_pos.y = 0;
	(*player)->step = 0;
}

void	init_data(t_data **data)
{
	(*data) = (t_data *)safe_malloc(sizeof(t_data));
	init_mlx_data(&(*data)->mlx_data);
	init_img_data((*data)->mlx_data, &(*data)->img_data);
	init_player((*data)->mlx_data, &(*data)->player);
}
