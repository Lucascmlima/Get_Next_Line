/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarvalh <lcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:23 by lcarvalh          #+#    #+#             */
/*   Updated: 2025/06/01 16:27:05 by lcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_lidos;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	bytes_lidos = 1;
	while (!br_test(line))
	{
		if (*buffer[fd] == '\0')
		{
			bytes_lidos = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_lidos < 0)
				return (free(line), NULL);
			else if (bytes_lidos == 0)
				return (line);
			buffer[fd][bytes_lidos] = '\0';
		}
		line = ft_strjoin(line, buffer[fd]);
		cleanse(buffer[fd]);
	}
	return (line);
}
