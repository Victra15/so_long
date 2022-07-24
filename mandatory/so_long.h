/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:22:56 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 03:07:42 by yolee            ###   ########.fr       */
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
# define LEFT_PAD 100
# define TOP_PAD 100
# define MAP_MAX_WIDTH 16
# define MAP_MAX_HEIGHT 16
# define COLLECT_FLAG 0
# define EXIT_FLAG 1
# define PLAYER_FLAG 2
# define KEYCODE_ESC 53
# define KEYCODE_UP 126
# define KEYCODE_DOWN 125
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124
# define KEYCODE_W 13
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2
# define MAP_DIR "./maps"

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}t_img;

typedef struct s_player
{
	t_img	*character_img;
	t_pos	player_pos;
	int		step;
}t_player;

typedef struct s_img_data
{
	t_img		*exit_img;
	t_img		*collect_img;
	t_img		*wall_img;
	t_img		*tile_img;
}t_img_data;

typedef struct s_map
{
	char	**map_data;
	int		collect_num;
	int		width;
	int		height;
}t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}t_mlx;

typedef struct s_data
{
	t_mlx		*mlx_data;
	t_img_data	*img_data;
	t_player	*player;
	t_map		*map;
}t_data;

char	*get_next_line(int fd);

void	*safe_malloc(size_t	mal_size);
void	safe_free(void	**alloc_mem);
void	exit_with_custom_err_msg(char *custom_msg);
void	exit_with_err_msg(void);

void	init_img(t_mlx *mlx, t_img **img, char *filename);
void	init_data(t_data **mlx_data);

t_map	*map_load(int argc, char **argv);
void	put_image_aligned_by_center(t_data *data,
			t_img *img,
			t_pos pos);
void	map_render(t_data *data);

void	map_error_check(t_map *map);
void	key_event(int keycode, t_data *data);
void	exit_game(t_data *data);

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

void	print_move_cnt(int *player_step);
int		move_condition_check(t_map *map, t_player *player, t_pos move_pos);
#endif