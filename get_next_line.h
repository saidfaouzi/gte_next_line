/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:34:14 by sfaouzi           #+#    #+#             */
/*   Updated: 2024/11/26 15:34:16 by sfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# if BUFFER_SIZE < 0 || BUFFER_SIZE == 2147483647
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*after_newline(char **str, int i);
char	*before_newline(char **li, char **rest, int i);
int		search(char *str);
char	*get_next_line(int fd);

#endif
