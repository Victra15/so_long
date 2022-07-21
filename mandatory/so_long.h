/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:22:56 by yolee             #+#    #+#             */
/*   Updated: 2022/07/20 23:05:43 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# define BUFFER_SIZE 100
# define MAP_MAX_WIDTH 16
# define MAP_MAX_HEIGHT 16
# define COLLECT_FLAG 0
# define EXIT_FLAG 1
# define PLAYER_FLAG 2
# define MAP_DIR "./maps"

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_map
{
	char	**map_data;
	int		width;
	int		height;
}t_map;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	t_map	*map;
	t_pos	player_pos;
}t_data;

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*get_next_line(int fd);

void	*safe_malloc(size_t	mal_size);
void	safe_free(void	**alloc_mem);
void	exit_with_custom_err_msg(char *custom_msg);
void	exit_with_err_msg(void);

void	init_mlx_data(t_data *mlx_data);
void	destroy_mlx_data(t_data *mlx_data);

t_map	*map_load(int argc, char **argv);

void	map_error_check(t_map *map);
#endif