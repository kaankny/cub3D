/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:58:02 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 16:06:10 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_pathfinder(char **map, int map_height, int x, int y)
{
	int	fl;

	fl = 0;
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 0 || map[y][x] == '\n' || map[y][x] == ' ')
		return (1);
	map[y][x] = '1';
	if (map[y][x + 1])
		fl += ft_pathfinder(map, map_height, x + 1, y);
	if (x - 1 >= 0)
		fl += ft_pathfinder(map, map_height, x - 1, y);
	if (y + 1 < map_height)
		fl += ft_pathfinder(map, map_height, x, y + 1);
	if (y - 1 >= 0)
		fl += ft_pathfinder(map, map_height, x, y - 1);
	if (fl > 0)
		return (1);
	return (0);
}
