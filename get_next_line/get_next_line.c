/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarvalh <lcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:23 by lcarvalh          #+#    #+#             */
/*   Updated: 2025/06/01 16:34:54 by lcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_lidos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (buffer[0] = 0, NULL);
	line = NULL;
	bytes_lidos = 1;
	while (!br_test(line))
	{
		if (*buffer == '\0')
			bytes_lidos = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lidos < 0)
			return (free(line), NULL);
		else if (bytes_lidos == 0)
			return (line);
		else
		{
			line = ft_strjoin(line, buffer);
			cleanse(buffer);
		}
	}
	return (line);
}
