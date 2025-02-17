/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:33:50 by sfaouzi           #+#    #+#             */
/*   Updated: 2024/11/26 15:33:53 by sfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*rest;
	char		buff[BUFFER_SIZE + 1];
	char		*li;
	int			len;
	int			i;

	if (rest == NULL)
		rest = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	len = read(fd, buff, BUFFER_SIZE);
	while (len >= 0)
	{
		buff[len] = '\0';
		rest = ft_strjoin(rest, buff);
		i = search(rest);
		if (i != -2)
			return (before_newline(&li, &rest, i));
		if (len == 0 && rest[0] == '\0')
			break ;
		if (len == 0)
			return (after_newline(&rest, 0));
		len = read(fd, buff, BUFFER_SIZE);
	}
	return (free(rest), rest = NULL, NULL);
}
