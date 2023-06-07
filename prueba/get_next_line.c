/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:41:14 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/06 18:49:43 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_clean_line(char *acum_str)
{
	int		i;
	int		j;
	char	*ret_str;

	i = 0;
	while (acum_str[i] != '\0' && acum_str[i] != '\n')
		i++;
	if (acum_str[i] == '\0')
	{
		free(acum_str);
		return (NULL);
	}
	ret_str = ft_calloc((ft_strlen(acum_str) - i + 1), sizeof(char));
	if (!ret_str)
		return (free(acum_str), NULL);
	i++;
	j = 0;
	while (acum_str[i] != '\0')
		ret_str[j++] = acum_str[i++];
	ret_str[j] = '\0';
	return (free(acum_str), ret_str);
}

static char	*get_actual_line(char *acum_str)
{
	char	*ret_str;
	int		i;

	i = 0;
	if (acum_str[i] == '\0')
		return (NULL);
	while (acum_str[i] != '\0' && acum_str[i] != '\n')
		i++;
	ret_str = ft_calloc((i + 1 + (acum_str[i] == '\n')), sizeof(char));
	if (!ret_str)
		return (NULL);
	i = 0;
	while (acum_str[i] != '\0' && acum_str[i] != '\n')
	{
		ret_str[i] = acum_str[i];
		i++;
	}
	if (acum_str[i] != '\0' && acum_str[i] == '\n')
		ret_str[i++] = '\n';
	ret_str[i] = '\0';
	return (ret_str);
}

static char	*get_joint(char *acum_str, char *buff)
{
	char	*r;

	r = ft_strjoin(acum_str, buff);
	if (!r)
		return (NULL);
	return (r);
}

static char	*get_a_lot(int fd, char *acum_str)
{
	char	*tmp;
	int		read_char;

	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmp)
		return (free(acum_str), NULL);
	read_char = 1;
	while (read_char > 0 && !ft_strchr_mod(tmp, '\n'))
	{
		read_char = read(fd, tmp, BUFFER_SIZE);
		if (read_char < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_char] = '\0';
		acum_str = get_joint(acum_str, tmp);
		if (!acum_str)
			return (free(acum_str), free(tmp), NULL);
	}
	return (free(tmp), acum_str);
}

char	*get_next_line(int fd)
{
	static char	*acum_str;
	char		*actual_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (acum_str != NULL)
		{
			free(acum_str);
			acum_str = NULL;
		}
		return (NULL);
	}
	acum_str = get_a_lot(fd, acum_str);
	if (!acum_str)
		return (free(acum_str), acum_str = NULL, NULL);
	actual_line = get_actual_line(acum_str);
	if (!actual_line)
		return (free(acum_str), acum_str = NULL, NULL);
	acum_str = get_clean_line(acum_str);
	if (!acum_str)
		return (free(acum_str), acum_str = NULL, actual_line);
	return (actual_line);
}
