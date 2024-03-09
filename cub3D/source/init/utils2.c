/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:35:31 by fduvan            #+#    #+#             */
/*   Updated: 2024/03/07 15:00:44 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memory.h"
#include "../../include/utils.h"
#include "../../include/cub3d.h"
#include "../../get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	get_lines(t_game *game)
{
	int		y;
	char	*line;

	y = 0;
	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
	{
		printf("\x1b[31mError\x1b[0m: Failed to open map file!\n");
		exit_game(game);
	}
	game->map.lines = _calloc(game->map.height + 1, sizeof(char *));
	line = get_next_line(game->map.fd);
	while (line)
	{
		game->map.lines[y] = ft_strdup(line);
		_free(line);
		line = get_next_line(game->map.fd);
		y++;
	}
	close(game->map.fd);
}

void	get_map_height(t_game *game)
{
	int		y;
	char	*line;

	y = 0;
	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
	{
		printf("\x1b[31mError\x1b[0m: Failed to open map file!\n");
		exit_game(game);
	}
	line = get_next_line(game->map.fd);
	while (line)
	{
		y++;
		_free(line);
		line = get_next_line(game->map.fd);
	}
	close(game->map.fd);
	game->map.height = y;
}
