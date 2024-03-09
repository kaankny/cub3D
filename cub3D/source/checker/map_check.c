/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:19:49 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 14:58:31 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/utils.h"
#include "../../include/memory.h"
#include "../../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	set_direction2(t_game *game, enum e_direction direction)
{
	if (direction == 2)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	if (direction == 3)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

void	set_direction(t_game *game, char c)
{
	enum e_direction	direction;

	direction = get_direction(c);
	game->player.direction = direction;
	if (direction == 0)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	if (direction == 1)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	set_direction2(game, direction);
}

void	check_map_2(t_game *game, char **map, int i, int j)
{
	if (i == 0 || i == game->map.height - 1 || j == 0
		|| j == ft_strlen(map[i]) - 2)
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\n')
			exit_safe(printf("\x1b[31mError\x1b[0m: Map is not " \
				"surrounded by walls!\n") * 0 + 1);
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
		|| map[i][j] == 'E')
	{
		if (game->player.x != -1 || game->player.y != -1)
			exit_safe(printf("\x1b[31mError\x1b[0m: Multiple player" \
				" characters in the map!\n") * 0 + 1);
		set_direction(game, map[i][j]);
		game->player.x = j + 0.5;
		game->player.y = i + 0.5;
	}
	if (!is_valid_map_char(map[i][j]))
		exit_safe(printf("\x1b[31mError\x1b[0m: Invalid map character " \
			"at line %d, column %d!\n", i + 1, j + 1) * 0 + 1);
}

void	check_map(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = game->map.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			check_map_2(game, map, i, j);
			j++;
		}
		i++;
	}
	if (game->player.x == -1 || game->player.y == -1)
	{
		printf("\x1b[31mError\x1b[0m: No player character in the map!\n");
		exit_game(game);
	}
}
