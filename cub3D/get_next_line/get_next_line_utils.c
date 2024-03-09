/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:09:05 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/24 16:31:21 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/memory.h"
#include "../include/utils.h"

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash)
		return (0);
	if (create_line == 0)
	{
		if (*stash)
		{
			_free(*stash);
			*stash = 0;
		}
		return (0);
	}
	else if (create_line == 1)
	{
		line = ft_strdup(*stash);
		_free(*stash);
		*stash = 0;
		return (line);
	}
	return (0);
}
