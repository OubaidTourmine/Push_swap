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
	static char	*left_c;
	char		*buffer;
	char		*line;
	char		*temp;
	int			i;

	i = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	left_c = fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	if (left_c == NULL)
		return (NULL);
	while (left_c[i] != '\n' && left_c[i] != '\0')
		i++;
	line = ft_substr(left_c, 0, i + 1);
	temp = ft_substr(left_c, i + 1, ft_strlen(left_c));
	free(left_c);
	left_c = temp;
	return (line);
}
