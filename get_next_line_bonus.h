/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alenzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:18:37 by alenzini          #+#    #+#             */
/*   Updated: 2022/11/08 19:19:05 by alenzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(char *a);
int		find_end_line(char *a);
void	put_buffer(char **a, char *buffer);
char	*get_line(char **a);
char	*get_next_line(int fd);

#endif
