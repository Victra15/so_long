/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:15:57 by yolee             #+#    #+#             */
/*   Updated: 2022/07/20 23:07:53 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	safe_free(void	**alloc_mem)
{
	if ((*alloc_mem) != NULL)
		free(*alloc_mem);
	(*alloc_mem) = NULL;
}

void	*safe_malloc(size_t mal_size)
{
	void	*mal_ptr;

	mal_ptr = malloc(mal_size);
	if (mal_ptr == NULL)
		exit_with_err_msg();
	return (mal_ptr);
}

void	exit_with_custom_err_msg(char *custom_msg)
{
	write(2, "Error\n", 6);
	if (custom_msg != NULL)
		write(2, custom_msg, ft_strlen(custom_msg));
	exit(1);
}

void	exit_with_err_msg(void)
{
	perror("Error\n");
	exit(1);
}
