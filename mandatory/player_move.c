/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:42:16 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 02:49:33 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_moved_img(t_data *data, t_pos move_pos, t_pos *player_pos)
{
	if (data->map->map_data[move_pos.y][move_pos.x] == 'C')
		data->map->collect_num--;
	data->map->map_data[move_pos.y][move_pos.x] = 'P';
	data->map->map_data[player_pos->y][player_pos->x] = '0';
	put_image_aligned_by_center(data, data->img_data->tile_img, (*player_pos));
	put_image_aligned_by_center(data, data->img_data->tile_img, move_pos);
	put_image_aligned_by_center(data, data->player->character_img, move_pos);
	print_move_cnt(&data->player->step);
	player_pos->x = move_pos.x;
	player_pos->y = move_pos.y;
}

void	move_up(t_data *data)
{
	t_pos	move_pos;
	t_pos	*player_pos;

	player_pos = &data->player->player_pos;
	move_pos.x = player_pos->x;
	move_pos.y = player_pos->y - 1;
	if (!move_condition_check(data->map, data->player, move_pos))
		return ;
	render_moved_img(data, move_pos, player_pos);
}

void	move_down(t_data *data)
{
	t_pos	move_pos;
	t_pos	*player_pos;

	player_pos = &data->player->player_pos;
	move_pos.x = player_pos->x;
	move_pos.y = player_pos->y + 1;
	if (!move_condition_check(data->map, data->player, move_pos))
		return ;
	render_moved_img(data, move_pos, player_pos);
}

void	move_left(t_data *data)
{
	t_pos	move_pos;
	t_pos	*player_pos;

	player_pos = &data->player->player_pos;
	move_pos.x = player_pos->x - 1;
	move_pos.y = player_pos->y;
	if (!move_condition_check(data->map, data->player, move_pos))
		return ;
	render_moved_img(data, move_pos, player_pos);
}

void	move_right(t_data *data)
{
	t_pos	move_pos;
	t_pos	*player_pos;

	player_pos = &data->player->player_pos;
	move_pos.x = player_pos->x + 1;
	move_pos.y = player_pos->y;
	if (!move_condition_check(data->map, data->player, move_pos))
		return ;
	render_moved_img(data, move_pos, player_pos);
}
