/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:04:03 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/28 16:01:13 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*cut_line(char *s);
int		sizeof_line(char *str);

#endif