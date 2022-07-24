/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:32:35 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 03:07:47 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_aligned_by_center(t_data *data,
	t_img *img,
	t_pos pos)
{
	t_pos	put_pos;
	t_pos	p_pos;

	p_pos.x = (data->img_data->tile_img->width * (2 * pos.x + 1)) / 2;
	p_pos.y = (data->img_data->tile_img->height * (2 * pos.y + 1)) / 2;
	put_pos.x = LEFT_PAD + p_pos.x - (img->width / 2);
	put_pos.y = TOP_PAD + p_pos.y - (img->height / 2);
	mlx_put_image_to_window(data->mlx_data->mlx,
		data->mlx_data->mlx_win,
		img->img,
		put_pos.x,
		put_pos.y);
}

static void	map_read(t_data *data, t_pos pos)
{
	char	map_char;

	map_char = data->map->map_data[pos.y][pos.x];
	put_image_aligned_by_center(data, data->img_data->tile_img, pos);
	if (map_char == '1')
		put_image_aligned_by_center(data, data->img_data->wall_img, pos);
	else if (map_char == 'E')
		put_image_aligned_by_center(data, data->img_data->exit_img, pos);
	else if (map_char == 'P')
	{
		put_image_aligned_by_center(data, data->player->character_img, pos);
		data->player->player_pos.x = pos.x;
		data->player->player_pos.y = pos.y;
	}
	else if (map_char == 'C')
		put_image_aligned_by_center(data, data->img_data->collect_img, pos);
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
