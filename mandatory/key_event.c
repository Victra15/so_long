/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:28:22 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 03:01:54 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_event(int keycode, t_data *data)
{
	t_pos	move_pos;

	if (keycode == KEYCODE_ESC)
		exit(0);
	else if (keycode == KEYCODE_UP || keycode == KEYCODE_W)
		move_up(data);
	else if (keycode == KEYCODE_LEFT || keycode == KEYCODE_A)
		move_left(data);
	else if (keycode == KEYCODE_DOWN || keycode == KEYCODE_S)
		move_down(data);
	else if (keycode == KEYCODE_RIGHT || keycode == KEYCODE_D)
		move_right(data);
}
