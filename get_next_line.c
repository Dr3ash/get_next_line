/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alenzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:37:02 by alenzini          #+#    #+#             */
/*   Updated: 2022/11/08 18:56:34 by alenzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*a;
	int			dim;
	char		buffer[BUFFER_SIZE + 1];

	dim = read(fd, buffer, BUFFER_SIZE);
	while (dim > 0)
	{
		buffer[dim] = '\0';
		put_buffer(&a, buffer);
		if (find_end_line(a) != -1)
			return (get_line(&a));
		dim = read(fd, buffer, BUFFER_SIZE);
	}
	return (get_line(&a));
}
