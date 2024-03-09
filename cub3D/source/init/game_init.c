/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:35:14 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 14:59:18 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/utils.h"
#include "../../minilibx/mlx.h"
#include "../../include/memory.h"
#include <stdlib.h>
#include <stdio.h>

static void	player_struct_init(t_game *game)
{
	game->player.x = -1;
	game->player.y = -1;
	game->player.direction = NORTH;
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0;
	game->player.move_speed = 0.1;
	game->player.rot_speed = 0.04;
}

static void	map_struct_init(t_game *game, char *path)
{
	game->map.path = ft_strdup(path);
	game->map.fd = 0;
	game->map.lines = 0;
	game->map.map = 0;
	game->map.height = 0;
	game->map.tile_size = 64;
	game->map.wall.no_texture.path = 0;
	game->map.wall.so_texture.path = 0;
	game->map.wall.we_texture.path = 0;
	game->map.wall.ea_texture.path = 0;
	game->map.wall.no_texture.img = 0;
	game->map.wall.so_texture.img = 0;
	game->map.wall.we_texture.img = 0;
	game->map.wall.ea_texture.img = 0;
	game->map.wall.no_texture.width = 0;
	game->map.wall.so_texture.width = 0;
	game->map.wall.we_texture.width = 0;
	game->map.wall.ea_texture.width = 0;
	game->map.wall.no_texture.height = 0;
	game->map.wall.so_texture.height = 0;
	game->map.wall.we_texture.height = 0;
	game->map.wall.ea_texture.height = 0;
	game->map.floor_color.defined = false;
	game->map.ceiling_color.defined = false;
}

void	game_init(t_game *game, char *path)
{
	player_struct_init(game);
	map_struct_init(game, path);
}

void	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		printf("Error\nmlx_init failed\n");
		exit_safe(1);
	}
	game->mlx.win = mlx_new_window(game->mlx.mlx, W_WIDTH, W_HEIGHT, "cub3d");
	if (!game->mlx.win)
	{
		free(game->mlx.mlx);
		printf("Error\nmlx_new_window failed\n");
		exit_safe(1);
	}
}
