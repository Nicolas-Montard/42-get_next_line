/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:04:03 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/27 15:29:27 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(const char *s, unsigned int limit);
int		sizeof_line(char *str);

#endif