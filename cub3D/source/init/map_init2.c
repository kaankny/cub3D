/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:37:28 by fduvan            #+#    #+#             */
/*   Updated: 2024/03/07 16:05:27 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memory.h"
#include "../../include/utils.h"
#include "../../include/cub3d.h"
#include <stdio.h>

static void	set_info_values(t_game *game, int *info_count, char **split)
{
	if (ft_strcmp(split[0], "NO") == 0)
		*info_count += set_texture(game,
				&game->map.wall.no_texture, split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		*info_count += set_texture(game,
				&game->map.wall.so_texture, split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		*info_count += set_texture(game,
				&game->map.wall.we_texture, split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		*info_count += set_texture(game,
				&game->map.wall.ea_texture, split[1]);
	else if (ft_strcmp(split[0], "F") == 0)
		*info_count += set_color(&game->map.floor_color, split[1]);
	else if (ft_strcmp(split[0], "C") == 0)
		*info_count += set_color(&game->map.ceiling_color, split[1]);
}

int	get_infos(t_game *game)
{
	int		i;
	char	**split;
	int		info_count;

	i = 0;
	info_count = 0;
	while (game->map.lines[i])
	{
		split = ft_split(game->map.lines[i], ' ');
		set_info_values(game, &info_count, split);
		i++;
		free_split(split);
		if (info_count == 6)
			break ;
	}
	if (info_count != 6)
		exit_safe(printf("\x1b[31mError\x1b[0m: Invalid map file!\n")
			* 0 + 1);
	return (i);
}
