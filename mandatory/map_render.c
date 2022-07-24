/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:32:35 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 00:09:20 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_aligned_by_center(t_data *data,
	t_img *img,
	t_pos center_pos)
{
	t_pos	put_pos;

	put_pos.x = center_pos.x - (img->width / 2);
	put_pos.y = center_pos.y - (img->height / 2);
	mlx_put_image_to_window(data->mlx_data->mlx,
		data->mlx_data->mlx_win,
		img->img,
		put_pos.x,
		put_pos.y);
}

static void	map_read(t_data *data, t_pos pos)
{
	char	map_char;
	int		tile_width;
	int		tile_height;
	t_pos	p_pos;

	tile_width = data->img_data->tile_img->width;
	tile_height = data->img_data->tile_img->height;
	p_pos.x = (tile_width * (2 * pos.x + 1)) / 2;
	p_pos.y = (tile_height * (2 * pos.y + 1)) / 2;
	map_char = data->map->map_data[pos.y][pos.x];
	put_image_aligned_by_center(data, data->img_data->tile_img, p_pos);
	if (map_char == '1')
		put_image_aligned_by_center(data, data->img_data->wall_img, p_pos);
	else if (map_char == 'E')
		put_image_aligned_by_center(data, data->img_data->exit_img, p_pos);
	else if (map_char == 'P')
	{
		put_image_aligned_by_center(data, data->player->character_img, p_pos);
		data->player->player_pos.x = pos.x;
		data->player->player_pos.y = pos.y;
	}
	else if (map_char == 'C')
		put_image_aligned_by_center(data, data->img_data->collect_img, p_pos);
}

void	map_render(t_data *data)
{
	t_pos	loop;

	if (data->map->width > MAP_MAX_WIDTH || data->map->height > MAP_MAX_HEIGHT)
		exit_with_custom_err_msg("map is too big.");
	loop.y = 0;
	while (loop.y < data->map->height)
	{
		loop.x = 0;
		while (loop.x < data->map->width)
		{
			map_read(data, loop);
			loop.x++;
		}
		loop.y++;
	}
}
