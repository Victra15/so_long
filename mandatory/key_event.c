/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:28:22 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 00:42:25 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keycode, t_data *data)
{
	if (keycode == KEYCODE_ESC)
		exit_game(data);
	else if(keycode == KEYCODE_UP || keycode == KEYCODE_W)
		data->player->player_pos.y++;
	else if(keycode == KEYCODE_LEFT || keycode == KEYCODE_A)
		data->player->player_pos.x--;
	else if(keycode == KEYCODE_DOWN || keycode == KEYCODE_S)
		data->player->player_pos.y--;
	else if(keycode == KEYCODE_RIGHT || keycode == KEYCODE_D)
		data->player->player_pos.x++;
	printf("player x : %d player y : %d\n", data->player->player_pos.x, data->player->player_pos.y);
	return (0);
}

int	exit_game(t_data *data)
{
	exit(0);
	return (0);
}
