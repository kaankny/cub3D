/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:34:57 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/27 16:39:32 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/memory.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static void	name_check(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'b' || path[len - 2] != 'u' || path[len - 3] != 'c'
		|| path[len - 4] != '.')
		exit_safe(printf("\x1b[31mError\x1b[0m: Invalid file extension!\n")
			* 0 + 1);
}

static void	valid_check(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_safe(printf("\x1b[31mError\x1b[0m: File not found!\n") * 0 + 1);
	close(fd);
}

void	file_check(t_game *game)
{
	name_check(game->map.path);
	valid_check(game->map.path);
}
