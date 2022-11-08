/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alenzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:57:59 by alenzini          #+#    #+#             */
/*   Updated: 2022/11/08 19:38:27 by alenzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	find_end_line(char *a)
{
	int	i;

	i = -1;
	while (a[++i])
		if (a[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_substr(char *a, int start, int end)
{
	char	*s;
	int		i;

	if (start > end)
		return (NULL);
	s = malloc(end - start + 2);
	i = -1;
	while (++i + start <= end)
		s[i] = a[start + i];
	s[i] = '\0';
	return (s);
}

void	put_buffer(char **a, char *buffer)
{
	char	*s;
	int		i;
	int		j;

	if (!*a)
		*a = ft_substr("", 0, 0);
	s = malloc(ft_strlen(*a) + ft_strlen(buffer)+ 1);
	i = -1;
	while ((*a)[++i])
		s[i] = (*a)[i];
	j = 0;
	while (buffer[j])
		s[i++] = buffer[j++];
	s[i] = '\0';
	free(*a);
	*a = s;
}

char	*get_line(char **a)
{
	char	*s;
	char	*t;
	int		p;

	if (!*a)
		return (NULL);
	p = find_end_line(*a);
	if (p == -1)
		p = ft_strlen(*a) - 1;
	s = ft_substr(*a, 0, p);
	t = ft_substr(*a, p + 1, ft_strlen(*a) - 1);
	free(*a);
	*a = t;
	return (s);
}
