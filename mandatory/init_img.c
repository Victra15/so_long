/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:08:49 by yolee             #+#    #+#             */
/*   Updated: 2022/07/23 21:31:31 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_mlx *mlx, t_img **img, char *filename)
{
	(*img) = (t_img *)safe_malloc(sizeof(t_img));
	(*img)->img = mlx_xpm_file_to_image(mlx, filename,
			&(*img)->width,
			&(*img)->height);
	if ((*img)->img == NULL)
		exit_with_custom_err_msg("image file not found.");
	(*img)->addr = mlx_get_data_addr((*img)->img,
			&(*img)->bits_per_pixel,
			&(*img)->line_length,
			&(*img)->endian);
}
