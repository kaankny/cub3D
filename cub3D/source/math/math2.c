/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:40:50 by fduvan            #+#    #+#             */
/*   Updated: 2024/03/06 14:19:07 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calc_texture_west_east(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->current_texture.width = game->map.wall.we_texture.width;
		ray->current_texture.height = game->map.wall.we_texture.height;
	}
	else
	{
		ray->current_texture.width = game->map.wall.ea_texture.width;
		ray->current_texture.height = game->map.wall.ea_texture.height;
	}
}

static void	calc_texture_north_south(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_y < 0)
	{
		ray->current_texture.width = game->map.wall.no_texture.width;
		ray->current_texture.height = game->map.wall.no_texture.height;
	}
	else
	{
		ray->current_texture.width = game->map.wall.so_texture.width;
		ray->current_texture.height = game->map.wall.so_texture.height;
	}
}

/*
** This function calculates the current texture width and height
*/
void	calc_texture_width_height(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		calc_texture_west_east(game, ray);
	else
		calc_texture_north_south(game, ray);
}

/*
** This function calculates the distance projected on camera direction
*/
void	calc_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

/*
** This function calc the lowest and highest pixel to fill in cur stripe
*/
void	calc_start_end_draw(t_ray *ray)
{
	ray->line_h = (int)(W_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_h / 2 + W_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + W_HEIGHT / 2;
	if (ray->draw_end >= W_HEIGHT)
		ray->draw_end = W_HEIGHT - 1;
}
