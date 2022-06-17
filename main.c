/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 06:05:15 by yolee             #+#    #+#             */
/*   Updated: 2022/06/17 09:13:55 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	printf("addr: %s\n", img.addr);
	printf("bits_per_pixel: %d\n", img.bits_per_pixel);
	printf("line_length: %d\n", img.line_length);
	printf("endian: %d\n", img.endian);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	printf("addr: %s\n", img.addr);
	printf("bits_per_pixel: %d\n", img.bits_per_pixel);
	printf("line_length: %d\n", img.line_length);
	printf("endian: %d\n", img.endian);
	return (0);
}
