/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:42 by fduvan            #+#    #+#             */
/*   Updated: 2024/03/07 15:29:11 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../minilibx/mlx.h"

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < W_WIDTH)
	{
		calc_ray_pos_dir(game, &ray, x);
		ray.map_x = (int)game->player.x;
		ray.map_y = (int)game->player.y;
		calc_ray_delta_dist(&ray);
		calc_ray_step_side_dist(game, &ray);
		perform_dda(game, &ray);
		calc_texture_width_height(game, &ray);
		calc_perp_wall_dist(&ray);
		calc_start_end_draw(&ray);
		calc_texture(game, &ray);
		draw_line(game, x, &ray);
		x++;
	}
}

int	game_loop(t_game *game)
{
	player_movement(game);
	player_rotation(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	return (0);
}
