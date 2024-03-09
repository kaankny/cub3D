/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:08:54 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/08 17:49:08 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/utils.h"
#include "../../include/memory.h"
#include "../../get_next_line/get_next_line.h"
#include "../../minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	set_texture(t_game *game, t_image *texture, char *path)
{
	if (texture->path)
		exit_safe(printf("\x1b[31mError\x1b[0m: Duplicate texture!\n")
			* 0 + 1);
	texture->path = ft_strtrim(path, " \n\t\v\f\r");
	texture->img = mlx_xpm_file_to_image(game->mlx.mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img)
		exit_safe(printf("\x1b[31mError\x1b[0m: Failed to load texture!\n")
			* 0 + 1);
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	return (1);
}

int	set_color(t_color *color, char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(line, ',');
	if (arr_len(split) != 3)
		exit_safe(printf("\x1b[31mError\x1b[0m: Invalid color!\n")
			* 0 + 1);
	check_is_digit(split);
	if (split[0] && split[1] && split[2] && color->defined == false)
	{
		r = ft_atoi(split[0]);
		g = ft_atoi(split[1]);
		b = ft_atoi(split[2]);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			exit_safe(printf("\x1b[31mError\x1b[0m: Invalid color!\n")
				* 0 + 1);
		color->r = r;
		color->g = g;
		color->b = b;
		color->defined = true;
		return (1);
	}
	return (0);
}

void	get_map(t_game *game, int i)
{
	int		j;

	while (game->map.lines[i])
	{
		j = 0;
		while (game->map.lines[i][j] == ' '
			|| game->map.lines[i][j] == '\t'
			|| game->map.lines[i][j] == '\n' || game->map.lines[i][j] == '\v'
			|| game->map.lines[i][j] == '\f' || game->map.lines[i][j] == '\r')
			j++;
		if (game->map.lines[i][j] != '\0')
			break ;
		i++;
	}
	game->map.map = _calloc(game->map.height - i + 1, sizeof(char *));
	j = 0;
	while (game->map.lines[i])
	{
		game->map.map[j] = ft_strdup(game->map.lines[i]);
		i++;
		j++;
	}
	game->map.map[j] = NULL;
	game->map.height = j;
}

void	copy_map(t_game *game)
{
	int	i;
	int	j;
	int	line_len;

	i = 0;
	line_len = get_longest_line(game->map.map);
	game->map.tmp_map = _calloc(game->map.height, sizeof(char *));
	while (game->map.map[i])
	{
		j = 0;
		game->map.tmp_map[i] = _calloc(line_len + 1, sizeof(char));
		while (game->map.map[i][j])
		{
			game->map.tmp_map[i][j] = game->map.map[i][j];
			j++;
		}
		i++;
	}
}

void	map_init(t_game *game)
{
	int	i;

	get_map_height(game);
	get_lines(game);
	i = get_infos(game);
	get_map(game, i);
	check_map(game);
	copy_map(game);
	if (ft_pathfinder(game->map.tmp_map, game->map.height,
			(int) game->player.x, (int) game->player.y) > 0)
		exit_safe(printf("\x1b[31mError\x1b[0m:  Map is not " \
			"surrounded by walls! :)!\n") * 0 + 1);
}
