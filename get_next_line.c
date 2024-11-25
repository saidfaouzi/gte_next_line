#include "get_next_line.h"

char *after_newline(char **str, int i)
{
    char *after;
    int len_a;

    len_a = ft_strlen(*str + i);
    after = ft_substr(*str, i, len_a);
    free(*str);
    *str = NULL;
    return (after);
}

char *before_newline(char **li, char **rest, int i)
{
    *li = ft_substr(*rest, 0, i + 1);
    *rest = after_newline(rest, i + 1);
    return (*li);
}

int search(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return (i);
        i++;
    }
return (-2);
}

char *get_next_line(int fd)
{
    static char *rest;
    char buff[BUFF_SIZE + 1];
    char *li;
    int len;
    int i;

    if(rest == NULL)
        rest = ft_strdup("");
    len = read(fd, buff, BUFF_SIZE);
    while(len >= 0)
    {
        buff[len] = '\0';
        rest = ft_strjoin(rest, buff);
        i = search(rest);
        if(i != -2)
            return (before_newline(&li, &rest, i));
        if(len == 0 && rest[0] == '\0')
            break;
        if(len == 0)
            return (after_newline(&rest, 0));
        len = read(fd, buff, BUFF_SIZE);
    }
    free(rest);
    rest = NULL;
    return (NULL);
}
#include <stdio.h>
int main ()
{
    int i = open ("te.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(i)) != NULL)
    {
        printf("%s", line); // Print the line
        free(line);         // Free the allocated line to avoid memory leaks
    }
  
}