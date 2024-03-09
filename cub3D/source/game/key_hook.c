/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:45:08 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/07 15:00:40 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/memory.h"

int	key_press(int key_code, void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if (key_code == KEY_W)
		g->keys.w = true;
	if (key_code == KEY_A)
		g->keys.a = true;
	if (key_code == KEY_S)
		g->keys.s = true;
	if (key_code == KEY_D)
		g->keys.d = true;
	if (key_code == KEY_LEFT)
		g->keys.left = true;
	if (key_code == KEY_RIGHT)
		g->keys.right = true;
	if (key_code == KEY_ESC)
		exit_safe(0);
	return (0);
}

int	key_release(int key_code, void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if (key_code == KEY_W)
		g->keys.w = false;
	if (key_code == KEY_A)
		g->keys.a = false;
	if (key_code == KEY_S)
		g->keys.s = false;
	if (key_code == KEY_D)
		g->keys.d = false;
	if (key_code == KEY_LEFT)
		g->keys.left = false;
	if (key_code == KEY_RIGHT)
		g->keys.right = false;
	return (0);
}
