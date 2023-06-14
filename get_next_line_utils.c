/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:59:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/12 13:13:06 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != 0)
		count++;
	return (count);
}

int	ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}

void	*ft_calloc(size_t num_elements, size_t size)
{
	char			*memory_allocated;
	unsigned int	i;

	memory_allocated = (char *)malloc(num_elements * size);
	if (memory_allocated == NULL)
		return (NULL);
	i = 0;
	while (i < (num_elements * size))
		memory_allocated[i++] = '\0';
	return ((void *)memory_allocated);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_length;
	char	*result;
	int		i;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (free(s1), s1 = NULL, NULL);
	}
	if (!s1 || !s2)
		return (free(s1), s1 = NULL, NULL);
	s1_length = ft_strlen(s1);
	result = (char *)ft_calloc((s1_length + ft_strlen(s2) + 1), sizeof(char));
	if (!result)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
		result[s1_length + i] = s2[i];
	result[s1_length + i] = '\0';
	return (free(s1), s1 = NULL, result);
}
