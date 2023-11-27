#include "../inc/get_next_line.h"

char    *get_next_line(int fd)
{
    static char *str;
    char        *line;
    int         ret;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!(line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    if (!str)
        str = ft_strdup("");
    while (!ft_strchr(str, '\n') && (ret = read(fd, line, BUFFER_SIZE)) > 0)
    {
        line[ret] = '\0';
        str = ft_strjoin(str, line);
    }
    free(line);
    if (ret < 0)
        return (NULL);
    return (ft_get_line(&str));
}

char    *ft_get_line(char **str)
{
    char    *line;
    char    *tmp;
    int     i;

    i = 0;
    while ((*str)[i] && (*str)[i] != '\n')
        i++;
    if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    line[i] = '\0';
    while (i--)
        line[i] = (*str)[i];
    if ((*str)[i] == '\n')
        i++;
    tmp = ft_strdup(*str + i);
    free(*str);
    *str = tmp;
    return (line);
}

char    *ft_strdup(char *s1)
{
    char    *s2;
    int     i;

    i = 0;
    while (s1[i])
        i++;
    if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    s2[i] = '\0';
    while (i--)
        s2[i] = s1[i];
    return (s2);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *s3;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (NULL);
    while (s1[i])
        i++;
    while (s2[j])
        j++;
    if (!(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
        return (NULL);
    s3[i + j] = '\0';
    while (j--)
        s3[i + j] = s2[j];
    while (i--)
        s3[i] = s1[i];
    free(s1);
    return (s3);
}

char    *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (s + i);
        i++;
    }
    if (s[i] == c)
        return (s + i);
    return (NULL);
}
