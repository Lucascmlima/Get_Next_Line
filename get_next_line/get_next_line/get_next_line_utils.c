/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarvalh <lcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:23 by lcarvalh          #+#    #+#             */
/*   Updated: 2025/05/25 16:48:03 by lcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	l;

	l = 0;
	i = 0;
	while (s1[l])
		l++;
	copy = malloc(l + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	full = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!full)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		full[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		full[i + j] = s2[j];
		j++;
	}
	full[i + j] = '\0';
	return (full);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (malloc(1));
	if (len > s_len - start)
		sub_len = s_len - start;
	else
		sub_len = len;
	res = malloc(sub_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
