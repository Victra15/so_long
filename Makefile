# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 06:35:36 by yolee             #+#    #+#              #
#    Updated: 2022/07/24 23:43:21 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = so_long
MLX_DIR = ./mlx
LIBFT_DIR = ./libft
MAND_DIR = ./mandatory
BONUS_DIR = ./bonus
SRCS_FILE_M = error_handle.c \
	get_next_line.c \
	main.c \
	map_error_check.c \
	map_load.c \
	init_mlx_data.c \
	init_img.c \
	map_render.c \
	key_event.c \
	
SRCS_M = $(addprefix $(MAND_DIR)/, $(SRCS_FILE_M))

SRCS_FILE_B = error_handle.c \
	get_next_line.c \
	main.c \
	map_error_check.c \
	map_load.c \
	mlx_data_cntl.c \

SRCS_B = $(addprefix $(BONUS_DIR)/, $(SRCS_FILE_B))

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef BONUS_FLAG
	NAME = $(addprefix $(BONUS_DIR)/, $(TARGET))
	SRCS = $(SRCS_B)
	OBJS = $(OBJS_B)
else
	NAME = $(addprefix $(MAND_DIR)/, $(TARGET))
	SRCS = $(SRCS_M)
	OBJS = $(OBJS_M)
endif

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) bonus -C $(LIBFT_DIR)
	$(CC) $(OBJS) -I $(LIBFT_DIR) -L$(LIBFT_DIR) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -I $(LIBFT_DIR) -L$(LIBFT_DIR) -lft -Imlx -c $< -o $@

bonus :
	$(MAKE) BONUS_FLAG=1 all
clean :
	$(MAKE) clean -C $(MLX_DIR) 
	$(MAKE) fclean -C $(LIBFT_DIR) 
	$(RM) $(OBJS_M)
	$(RM) $(OBJS_B)

fclean : clean
	$(RM) $(MAND_DIR)/$(TARGET)
	$(RM) $(BONUS_DIR)/$(TARGET)

re : fclean all

.phony : all clean fclean re