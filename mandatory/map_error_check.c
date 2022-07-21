/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:25:29 by yolee             #+#    #+#             */
/*   Updated: 2022/07/21 16:14:06 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_invalid_map_char(t_map *map, int *exist_flag, int x, int y)
{
	char	map_char;

	map_char = map->map_data[y][x];
	if (map_char == '0'
		|| map_char == '1'
		|| map_char == 'C'
		|| map_char == 'E'
		|| map_char == 'P')
	{
		if (map_char == 'C' && exist_flag[COLLECT_FLAG] == 0)
			exist_flag[COLLECT_FLAG] = 1;
		if (map_char == 'E' && exist_flag[EXIT_FLAG] == 0)
			exist_flag[EXIT_FLAG] = 1;
		if (map_char == 'P' && exist_flag[PLAYER_FLAG] == 0)
			exist_flag[PLAYER_FLAG] = 1;
		if (x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
			if (map_char != '1')
				exit_with_custom_err_msg("map not surrounded by wall");
	}
	else
		exit_with_custom_err_msg("invalid map character.");
}

void	map_error_check(t_map *map)
{
	int	loop_x;
	int	loop_y;
	int	exist_flag[3];

	ft_bzero(exist_flag, sizeof(int) * 3);
	loop_y = 0;
	while (loop_y < map->height)
	{
		loop_x = 0;
		while (loop_x < map->width)
		{
			find_invalid_map_char(map, exist_flag, loop_x, loop_y);
			loop_x++;
		}
		loop_y++;
	}
	if (!(exist_flag[COLLECT_FLAG] == 1
			&& exist_flag[EXIT_FLAG] == 1
			&& exist_flag[PLAYER_FLAG] == 1))
		exit_with_custom_err_msg("player, collectiable, exit is missing.");
}
