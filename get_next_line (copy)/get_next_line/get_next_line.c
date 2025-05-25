/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarvalh <lcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:23 by lcarvalh          #+#    #+#             */
/*   Updated: 2025/05/25 18:37:44 by lcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &output_line, 0) < 0)
		return (NULL);
	output_line = NULL;
	bytes_read = 1;
	while (!new_line(output_line))
	{
		if (*buffer == '\0')
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(output_line), NULL);
		else if (bytes_read == 0)
			return (output_line);
		else
		{
			output_line = copy_to_line(output_line, buffer);
			cleanse(buffer);
		}
	}
	return (output_line);
}

// int main()
// {
// 	int fd;
// 	char	*line;	
// 	fd = open("teste.txt", O_RDONLY);
// 	line = malloc(BUFFER_SIZE + 1);
// 	if(!line)
// 		return (1);
// 	if(fd < 0)
// 	{
// 		perror("Erro ao abrir o arquivo.");
// 		return (1);
// 	}
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
