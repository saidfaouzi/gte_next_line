/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:40 by sfaouzi           #+#    #+#             */
/*   Updated: 2024/11/27 15:49:43 by sfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*after_newline(char **str, int i)
{
	char	*after;
	int		len_a;

	len_a = ft_strlen(*str + i);
	after = ft_substr(*str, i, len_a);
	free(*str);
	*str = NULL;
	return (after);
}

char	*before_newline(char **li, char **rest, int i)
{
	*li = ft_substr(*rest, 0, i + 1);
	*rest = after_newline(rest, i + 1);
	return (*li);
}

int	search(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-2);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		buff[BUFFER_SIZE + 1];
	char		*li;
	int			len;
	int			i;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	len = read(fd, buff, BUFFER_SIZE);
	while (len >= 0)
	{
		buff[len] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buff);
		i = search(rest[fd]);
		if (i != -2)
			return (before_newline(&li, &rest[fd], i));
		if (len == 0 && rest[fd][0] == '\0')
			break ;
		if (len == 0)
			return (after_newline(&rest[fd], 0));
		len = read(fd, buff, BUFFER_SIZE);
	}
	return (free(rest[fd]), rest[fd] = NULL, NULL);
}
