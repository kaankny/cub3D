/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:11:43 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/03 16:18:09 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/utils.h"
#include "../../include/memory.h"
#include <stdio.h>

enum e_direction	get_direction(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'W')
		return (WEST);
	if (c == 'E')
		return (EAST);
	return (0);
}

int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == '\n')
		return (1);
	return (0);
}

char	**dublicate_map(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = _calloc(game->map.height + 1, sizeof(char *));
	if (!map)
		exit_safe(printf("\x1b[31mError\x1b[0m: Failed " \
			"to allocate memory for map dublicate!\n") * 0 + 1);
	while (game->map.map[i])
	{
		map[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		_free(map[i]);
		i++;
	}
	_free(map);
}
