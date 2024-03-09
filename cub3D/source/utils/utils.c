/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:44:51 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/04 12:12:54 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memory.h"
#include "../../include/utils.h"
#include <stdlib.h>

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	arr = (char **)_malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		k = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > k)
		{
			arr[j] = ft_substr(str, k, i - k);
			j++;
		}
	}
	arr[j] = 0;
	return (arr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*dst_c;
	unsigned char	*src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	str = (char *)_malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = (char *)_malloc(len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s, len);
	str[len] = 0;
	return (str);
}
