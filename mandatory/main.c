/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:04 by yolee             #+#    #+#             */
/*   Updated: 2022/07/21 16:21:28 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*mlx_data;
	int loop_x;
	int loop_y;

	mlx_data = (t_data *)safe_malloc(sizeof(t_data));
	mlx_data->map = map_load(argc, argv);
	loop_y = 0;
	while (loop_y < mlx_data->map->height)
	{
		printf("%s\n", mlx_data->map->map_data[loop_y]);
		loop_y++;
	}
	system("leaks so_long");
	// init_mlx_data(mlx_data);
	// mlx_loop(mlx_data->mlx);
	return (0);
}
