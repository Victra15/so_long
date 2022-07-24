/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:31:04 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 02:56:09 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move_cnt(int *player_step)
{
	(*player_step)++;
	printf("step count : %d\n", (*player_step));
}

int	move_condition_check(t_map *map, t_player *player, t_pos move_pos)
{
	if (map->map_data[move_pos.y][move_pos.x] == '1')
		return (0);
	if (map->map_data[move_pos.y][move_pos.x] == 'E')
	{
		if (map->collect_num != 0)
			return (0);
		else
		{
			print_move_cnt(&player->step);
			exit(0);
		}
	}
}

