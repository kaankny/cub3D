/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:03:29 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/03 15:23:00 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

void	*_malloc(unsigned int size);
void	*_calloc(unsigned int count, unsigned int size);
void	_free(void *ptr);
void	exit_safe(int status);

#endif