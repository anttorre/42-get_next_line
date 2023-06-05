/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:24:36 by anttorre          #+#    #+#             */
/*   Updated: 2023/05/30 17:26:28 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fichero;
	char	*line;

	fichero = open("test.txt", O_RDONLY);
	if (fichero < 0)
		printf("El fichero no existe\n");
	printf("El contenido del fichero es:\n");
	line = get_next_line(fichero);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fichero);
	}
	close(fichero);
	free(line);
	return (0);
}
