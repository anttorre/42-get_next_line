/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:27:22 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/01 16:35:42 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer_size(int fd, char *buffer)
{
	int		r;
	char	*aux_buffer;

	aux_buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!aux_buffer)
		return (free(buffer), buffer = NULL, NULL);
	r = 1;
	while (r && !ft_strchr(buffer, '\n'))
	{
		r = read(fd, aux_buffer, BUFFER_SIZE);
		if (r < 0)
			return (free(buffer), buffer = NULL, free(aux_buffer),
				aux_buffer = NULL, NULL);
		aux_buffer[r] = '\0';
		buffer = ft_strjoin(buffer, aux_buffer);
		if (!buffer)
			return (free(buffer), buffer = NULL, free(aux_buffer),
				aux_buffer = NULL, NULL);
	}
	return (free(aux_buffer), aux_buffer = NULL, buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[0] == '\0')
		return (NULL);
	line = (char *)ft_calloc((i + 1 + (buffer[i] == '\n')), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_rest_buffer(char *buffer)
{
	char	*aux_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	aux_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!aux_buffer)
		return (free(buffer), buffer = NULL, NULL);
	j = 0;
	while (buffer[++i])
		aux_buffer[j++] = buffer[i];
	aux_buffer[j] = '\0';
	return (free(buffer), buffer = NULL, aux_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
	{
		if (buffer != NULL)
			return (free(buffer), buffer = NULL, NULL);
		return (NULL);
	}
	buffer = read_buffer_size(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = ft_get_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = get_rest_buffer(buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, line);
	return (line);
}
