/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:12:06 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/01 15:51:15 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	dest_len_size;

	i = 0;
	dest_len = 0;
	dest_len_size = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (dest[dest_len_size] != '\0' && dest_len_size < size)
		dest_len_size++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size < 1)
		return (dest_len_size + src_len);
	while ((i + dest_len + 1) < size && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len_size + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*newstr;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!newstr)
	{
		free(s1);
		return (newstr);
	}
	newstr[0] = '\0';
	ft_strlcat(newstr, s1, s1_len + 1);
	ft_strlcat(newstr, s2, s1_len + s2_len + 1);
	free(s1);
	return (newstr);
}

char	*cut_line(char *s)
{
	int		s_len;
	char	*dest;
	int		i;

	i = 0;
	s_len = 0;
	while (s[s_len] != '\0' && s[s_len] != '\n')
		s_len++;
	if (s[s_len] == '\n')
		s_len++;
	dest = malloc(sizeof(char) * (s_len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < s_len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	sizeof_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}
