/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:15:09 by outourmi          #+#    #+#             */
/*   Updated: 2024/11/26 22:47:24 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	char	*temp;
	int		b_r;

	while (fd > 0 || BUFFER_SIZE >= 0)
	{
		b_r = read(fd, buffer, BUFFER_SIZE);
		if (b_r < 0)
		{
			free(left_c);
			return (NULL);
		}
		buffer[b_r] = '\0';
		if (left_c == NULL)
			left_c = ft_strdup(buffer);
		else
		{
			temp = left_c;
			left_c = ft_strjoin(temp, buffer);
			free(temp);
		}
		if (ft_strchr(left_c, '\n') || b_r == 0)
			break ;
	}
	return (left_c);
}

char	*get_next_line(int fd)
{
