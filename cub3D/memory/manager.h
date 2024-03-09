/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:02:49 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/03 15:21:05 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

typedef struct s_ptrs
{
	void			*ptr;
	struct s_ptrs	*next;
}	t_ptrs;

t_ptrs	**get_list(void);
void	free_list(t_ptrs **list);
void	add_list(t_ptrs **list, void *ptr);
void	remove_list(t_ptrs **list, void *ptr);
void	*ft_calloc(unsigned int count, unsigned int size);

#endif