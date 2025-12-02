/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:25:25 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/02 14:41:39 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static void	reset_stash(size_t limit, char stash[BUFFER_SIZE])
{
	int	i;

	i = 0;
	if (limit == 0)
	{
		stash[0] = '\0';
		return ;
	}
	while (stash[limit + i] != '\0')
	{
		stash[i] = stash[limit + i];
		i++;
	}
	stash[i] = '\0';
}

static void	fill_buffer_line(char stash[BUFFER_SIZE], int fd, char **buffer)
{
	int		byte_read;
	char	*temp_buffer;

	while (*buffer && !sizeof_line(*buffer))
	{
		byte_read = read(fd, stash, BUFFER_SIZE);
		if (byte_read < 1)
			break ;
		stash[byte_read] = '\0';
		*buffer = ft_strjoin(*buffer, stash);
	}
	if (byte_read < 0)
	{
		stash[0] = '\0';
		free(*buffer);
		*buffer = 0;
		return ;
	}
	temp_buffer = cut_line(*buffer);
	free(*buffer);
	*buffer = 0;
	if (temp_buffer == NULL)
		return ;
	*buffer = temp_buffer;
	return ;
}

static char	*get_line(char stash[BUFFER_SIZE], int fd)
{
	char	*buffer;
	int		i;
	int		size_of_line;

	i = 0;
	buffer = malloc(sizeof(char) * (ft_strlen(stash) + 1));
	if (buffer == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		buffer[i] = stash[i];
		i++;
	}
	buffer[i] = '\0';
	fill_buffer_line(stash, fd, &buffer);
	size_of_line = sizeof_line(stash);
	if (size_of_line)
		reset_stash(size_of_line, stash);
	else
		stash[0] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	stash[FD_MAX][BUFFER_SIZE + 1];
	char		*buffer;
	int			size_of_line;

	size_of_line = sizeof_line(stash[fd]);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (size_of_line)
	{
		buffer = cut_line(stash[fd]);
		if (buffer == NULL)
			return (0);
		reset_stash(size_of_line, stash[fd]);
		return (buffer);
	}
	buffer = get_line(stash[fd], fd);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	return (buffer);
}
