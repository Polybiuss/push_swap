/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:27:41 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/26 22:12:34 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen1(char *s);
char	*add_ptr1(char *s1, char *s2);
char	*ft_strchr1(char *s, int c);
size_t	ft_strlcpy1(char *dst, char *src, size_t size);
char	*ft_substr1(char *s, size_t start, size_t len);
char	*get_next_line(int fd);
#endif