/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:26:39 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/28 12:22:09 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"
#include <stdio.h>
#include <stdlib.h>

t_ptrs	**get_list(void)
{
	static t_ptrs	*g_ptrs = NULL;

	return (&g_ptrs);
}

void	free_list(t_ptrs **list)
{
	t_ptrs	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->ptr);
		free(tmp);
	}
}

void	add_list(t_ptrs **list, void *ptr)
{
	t_ptrs	*new;
	t_ptrs	*tmp;

	new = (t_ptrs *)malloc(sizeof(t_ptrs));
	if (!new)
	{
		printf("Memory allocation \x1b[31mfailed\x1b[0m\n");
		free_list(list);
		exit(1);
	}
	new->ptr = ptr;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	remove_list(t_ptrs **list, void *ptr)
{
	t_ptrs	*tmp;
	t_ptrs	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		if (tmp->ptr == ptr)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*list = tmp->next;
			free(tmp->ptr);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
