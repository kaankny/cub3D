/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:15 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 16:04:05 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	player_movement_y(t_game *game)
{
	if (game->keys.w)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
			+ game->player.dir_x * game->player.move_speed)] != '1')
			game->player.x += game->player.dir_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y + game->player.dir_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y += game->player.dir_y * game->player.move_speed;
	}
	if (game->keys.s)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
			- game->player.dir_x * game->player.move_speed)] != '1')
			game->player.x -= game->player.dir_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y - game->player.dir_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y -= game->player.dir_y * game->player.move_speed;
	}
}

static void	player_movement_x(t_game *game)
{
	if (game->keys.a)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
				- game->player.plane_x * game->player.move_speed)] != '1')
			game->player.x -= game->player.plane_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y - game->player.plane_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y -= game->player.plane_y * game->player.move_speed;
	}
	if (game->keys.d)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
				+ game->player.plane_x * game->player.move_speed)] != '1')
			game->player.x += game->player.plane_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y + game->player.plane_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y += game->player.plane_y * game->player.move_speed;
	}
}

void	player_movement(t_game *game)
{
	player_movement_x(game);
	player_movement_y(game);
}
