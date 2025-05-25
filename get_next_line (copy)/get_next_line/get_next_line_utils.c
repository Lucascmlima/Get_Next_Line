/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarvalh <lcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:23 by lcarvalh          #+#    #+#             */
/*   Updated: 2025/05/25 18:48:01 by lcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	char	*p;

	p = s;
	if (!s)
		return (0);
	while (*p)
		p++;
	return (p - s);
}

void	cleanse(char *buffer)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\0')
		i++;
	while (buffer[j])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*copy_to_line(char *output_line, char *buffer)
{
	char	*newline;
	char	*ptr;
	char	*to_free;

	newline = malloc(ft_strlen(buffer) + ft_strlen(output_line) + 1);
	if (!newline)
	{
		free(output_line);
		free(buffer);
		free(newline);
		return (NULL);
	}
	ptr = newline;
	to_free = output_line;
	while (output_line && *output_line)
		*ptr++ = *output_line++;
	while (*buffer && *buffer != '\n')
		*ptr++ = *buffer++;
	if (*buffer == '\n')
		*ptr++ = *buffer;
	free(to_free);
	*ptr = '\0';
	return (newline);
}

int	new_line(char *output_line)
{
	if (!output_line)
		return (0);
	while (*output_line && *output_line != '\n')
		output_line++;
	if (*output_line == '\n')
		return (1);
	return (0);
}
