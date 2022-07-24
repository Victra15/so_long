/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:28:27 by yolee             #+#    #+#             */
/*   Updated: 2022/07/25 00:41:32 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_name_check(char	*map_filename)
{
	size_t	filename_len;

	filename_len = ft_strlen(map_filename);
	if (filename_len < 4
		|| !(map_filename[filename_len - 4] == '.'
			&& map_filename[filename_len - 3] == 'b'
			&& map_filename[filename_len - 2] == 'e'
			&& map_filename[filename_len - 1] == 'r'))
		exit_with_custom_err_msg("invalid file name\n");
}

static	t_list	*make_char_lst(int fd, t_map **map)
{
	t_list	*line_lst;
	t_list	*temp_lst;
	char	*line;

	(*map)->height = 0;
	line_lst = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp_lst = ft_lstnew(line);
		if (line_lst == NULL)
		{
			line_lst = temp_lst;
			(*map)->width = ft_strlen(line);
		}
		else
		{
			ft_lstadd_back(&line_lst, temp_lst);
			if ((*map)->width != ft_strlen(line))
				exit_with_custom_err_msg("invalid map shape.");
		}
		(*map)->height++;
		line = get_next_line(fd);
	}
	return (line_lst);
}

static void	load_from_lst(t_map **map, t_list **lst)
{
	int		loop;
	t_list	*temp;

	(*map)->map_data = (char **)safe_malloc(sizeof(char *) * (*map)->height);
	loop = 0;
	while (loop < (*map)->height)
	{
		(*map)->map_data[loop] = (*lst)->content;
		temp = (*lst);
		(*lst) = (*lst)->next;
		safe_free((void **)&temp);
		loop++;
	}
}

static t_map	*load_from_file(char *filename)
{
	int		fd;
	t_list	*line_lst;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_with_err_msg();
	map = (t_map *)safe_malloc(sizeof(t_map));
	line_lst = make_char_lst(fd, &map);
	load_from_lst(&map, &line_lst);
	map_error_check(map);
	return (map);
}

t_map	*map_load(int argc, char **argv)
{
	char	*map_name;

	if (argc != 2)
		exit_with_custom_err_msg("invalid argument number.\n");
	map_name = argv[1];
	map_name_check(map_name);
	return (load_from_file(map_name));
}
