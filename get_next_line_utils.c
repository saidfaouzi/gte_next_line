#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		lens1;
	int		lens2;

	i = 0;
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	if (!s1 || !s2)
		return (NULL);
	result = malloc(lens1 + lens2 + 1);
	if (result == NULL)
		return (NULL);
	while (i < lens1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		result[i] = s2[i - lens1];
		i++;
	}
	free((void *)s1);
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