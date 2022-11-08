/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alenzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:23:28 by alenzini          #+#    #+#             */
/*   Updated: 2022/11/08 19:29:17 by alenzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*a[OPEN_MAX];
	int			dim;
	char		buffer[BUFFER_SIZE + 1];

	dim = read(fd, buffer, BUFFER_SIZE);
	while (dim > 0)
	{
		buffer[dim] = '\0';
		put_buffer(&a[fd], buffer);
		if (find_end_line(a[fd]) != -1)
			return (get_line(&a[fd]));
		dim = read(fd, buffer, BUFFER_SIZE);
	}
	return (get_line(&a[fd]));
}
