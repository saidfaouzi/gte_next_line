/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:15:22 by sfaouzi           #+#    #+#             */
/*   Updated: 2024/11/27 14:15:24 by sfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen((char *)s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	lens1;

	i = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	lens1 = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(lens1 + 1);
	if (result == NULL)
		return (NULL);
	while (i < lens1 - ft_strlen(s2))
	{
		result[i] = s1[i];
		i++;
	}
	while (i < lens1)
	{
		result[i] = s2[i - (lens1 - ft_strlen(s2))];
		i++;
	}
	free(s1);
	s1 = NULL;
	return (result[i] = '\0', result);
}

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
