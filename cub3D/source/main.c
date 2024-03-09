/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:03:47 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 14:55:01 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/memory.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	exit_game(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	free(g->mlx.mlx);
	exit_safe(0);
	return (0);
}

void	r_g_b_tocolor(t_color *color)
{
	color->color = (color->r << 16 | color->g << 8 | color->b);
	color->defined = true;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("\x1b[31mError\x1b[0m: Invalid number of arguments!\n"),
			1);
	game_init(&game, av[1]);
	file_check(&game);
	init_mlx(&game);
	map_init(&game);
	game.img.img = mlx_new_image(game.mlx.mlx, W_WIDTH, W_HEIGHT);
	game.img.addr = (int *)mlx_get_data_addr(game.img.img,
			&game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
	r_g_b_tocolor(&game.map.ceiling_color);
	r_g_b_tocolor(&game.map.floor_color);
	mlx_hook(game.mlx.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.mlx.win, 17, 1L << 17, exit_game, &game);
	mlx_loop_hook(game.mlx.mlx, game_loop, &game);
	mlx_loop(game.mlx.mlx);
	exit_safe(0);
	return (0);
}
