/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:04 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 02:17:33 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	init_data(&data);
	data->map = map_load(argc, argv);
	map_render(data);
	mlx_key_hook(data->mlx_data->mlx_win, key_event, data);
	mlx_hook(data->mlx_data->mlx_win, 17, 0, exit, NULL);
	mlx_loop(data->mlx_data->mlx);
	return (0);
}
