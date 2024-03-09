/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:31:09 by fduvan            #+#    #+#             */
/*   Updated: 2024/03/07 16:05:35 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memory.h"
#include "../../include/utils.h"
#include "../../include/cub3d.h"
#include <stdio.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		_free(split[i]);
		i++;
	}
	_free(split);
}

int	get_longest_line(char **map)
{
	int	i;
	int	longest_line;

	i = 0;
	longest_line = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > longest_line)
			longest_line = ft_strlen(map[i]);
		i++;
	}
	return (longest_line);
}

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	check_is_digit(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (j == 0)
			{
				if (split[i][j] == '\n')
					exit_safe(printf("\x1b[31mError\x1b[0m: Invalid color!\n")
						* 0 + 1);
			}
			if (!ft_isdigit(split[i][j]) && split[i][j] != '\n')
				exit_safe(printf("\x1b[31mError\x1b[0m: Invalid color!\n")
					* 0 + 1);
			j++;
		}
		i++;
	}
}
