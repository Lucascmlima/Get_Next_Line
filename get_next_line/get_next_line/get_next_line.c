/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarvalh <lcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:48:28 by lcarvalh          #+#    #+#             */
/*   Updated: 2025/05/25 16:45:44 by lcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;
	ssize_t		readed;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		stash = ft_strjoin_and_free(stash, buf);
	}
	free(buf);
	line = get_line_from_stash(stash);
	stash = clean_stash(stash);
	return (line);
}


char	*ft_strjoin_and_free(char *stash, char *buf)
{
	char	*new_str;

	if (!buf)
		return (NULL);
	if (!stash)
		return (ft_strdup(buf));
	new_str = ft_strjoin(stash, buf);
	free(stash);
	return (new_str);
}
char	*get_line_from_stash(char *stash)
{
	size_t	i;
	char	*res;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = ft_strjoin_and_free(stash, buf);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stash);
}
char	*clean_stash(char *stash)
{
	size_t	i;
	char	*clean;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	clean = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	return (clean);
}

// char	*update_stash(char *stash)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*new_stash;

// 	i = 0;
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	if (!stash[i])
// 	{
// 		free(stash);
// 		return (NULL);
// 	}
// 	new_stash = malloc(ft_strlen(stash) - i);
// 	if (!new_stash)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (stash[i])
// 		new_stash[j++] = stash[i++];
// 	new_stash[j] = '\0';
// 	free(stash);
// 	return (new_stash);
// }