/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:54:37 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/28 16:16:23 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	reset_stash(size_t limit, char stash[BUFFER_SIZE])
{
	int		i;
	char	temp_stash[BUFFER_SIZE];

	i = 0;
	while (stash[limit + i] != '\0')
	{
		temp_stash[i] = stash[limit + i];
		i++;
	}
	temp_stash[i] = '\0';
	i = 0;
	while (temp_stash[i] != '\0')
	{
		stash[i] = temp_stash[i];
		i++;
	}
	stash[i] = '\0';
}

static char	*get_line(char stash[BUFFER_SIZE], int fd)
{
	char	*buffer;
	char	*temp_buffer;
	int		i;
	int		byte_read;

	// TODO add sizeof_line var if space for it
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
	while (buffer && !sizeof_line(buffer) && ((byte_read = read(fd, stash, BUFFER_SIZE)) > 0))
	{
		stash[byte_read] = '\0';
		buffer = ft_strjoin(buffer, stash);
	}
	if(byte_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	temp_buffer = cut_line(buffer);
	free(buffer);
	if (temp_buffer == NULL)
		return (NULL);
	buffer = temp_buffer;
	if (sizeof_line(stash))
		reset_stash(sizeof_line(stash), stash);
	else
		stash[0] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// TODO add sizeof_line var if space for it
	if (sizeof_line(stash))
	{
		buffer = cut_line(stash);
		if (buffer == NULL)
			return (0);
		reset_stash(sizeof_line(stash), stash);
		return (buffer);
	}
	buffer = get_line(stash, fd);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	return (buffer);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	fd = open("nl", O_RDONLY);
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd);
// 		dprintf(1, "%s", line);
// 		if (line)
// 			free(line);
// 		i++;
// 	}
// 	close(fd);
// }
