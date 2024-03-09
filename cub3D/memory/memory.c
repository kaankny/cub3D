/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:02:26 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/06 12:51:38 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "manager.h"

void	exit_safe(int status)
{
	free_list(get_list());
	exit(status);
}

void	*_malloc(unsigned int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		printf("Memory allocation \x1b[31mfailed\x1b[0m\n");
		exit_safe(1);
	}
	add_list(get_list(), ptr);
	return (ptr);
}

void	*_calloc(unsigned int count, unsigned int size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		printf("Memory allocation \x1b[31mfailed\x1b[0m\n");
		exit_safe(1);
	}
	add_list(get_list(), ptr);
	return (ptr);
}

void	_free(void *ptr)
{
	if (ptr)
	{
		remove_list(get_list(), ptr);
		ptr = NULL;
	}
	else
	{
		printf("Attempt to free a \x1b[31mNULL\x1b[0m pointer\n");
		exit_safe(1);
	}
}
