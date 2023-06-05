/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:51:02 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/02 13:43:14 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_buffer_size(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*get_rest_buffer(char *buffer);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *str, int c);
void	*ft_calloc(size_t num_elements, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif
