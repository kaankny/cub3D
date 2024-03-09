/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:11:01 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 16:03:48 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_wall(t_game *game, int x, t_ray *ray, int y)
{
	if (ray->side == 1 && ray->ray_dir_y < 0)
		game->img.addr[y * W_WIDTH + x] = \
			game->map.wall.no_texture.addr
		[game->map.wall.no_texture.width * ray->texture.y + ray->texture.x];
	else if (ray->side == 1 && ray->ray_dir_y >= 0)
		game->img.addr[y * W_WIDTH + x] = \
			game->map.wall.so_texture.addr
		[game->map.wall.so_texture.width * ray->texture.y + ray->texture.x];
	if (ray->side == 0 && ray->ray_dir_x < 0)
		game->img.addr[y * W_WIDTH + x] = \
			game->map.wall.we_texture.addr
		[game->map.wall.we_texture.width * ray->texture.y + ray->texture.x];
	else if (ray->side == 0 && ray->ray_dir_x >= 0)
		game->img.addr[y * W_WIDTH + x] = \
			game->map.wall.ea_texture.addr
		[game->map.wall.ea_texture.width * ray->texture.y + ray->texture.x];
	ray->texture.pos += ray->step;
}

void	draw_line(t_game *game, int x, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < W_HEIGHT)
	{
		ray->texture.y = (int)ray->texture.pos;
		if (y < ray->draw_start)
			game->img.addr[y * W_WIDTH + x] = game->map.ceiling_color.color;
		else if (y > ray->draw_end)
			game->img.addr[y * W_WIDTH + x] = game->map.floor_color.color;
		else
			draw_wall(game, x, ray, y);
		y++;
	}
}
