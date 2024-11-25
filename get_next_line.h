#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFF_SIZE
#define BUFF_SIZE 1
#endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char *after_newline(char **str, int i);
char *before_newline(char **li, char **rest, int i);
int search(char *str);
char *get_next_line(int fd);

#endif