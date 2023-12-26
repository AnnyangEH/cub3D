#include "../inc/cub3D.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (FAILURE);
	while (i < n && (s1[i] || s2[i]))
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new)
		return (0);
	new[s1_len + s2_len] = 0;
	while (s2_len--)
		new[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		new[s1_len] = s1[s1_len];
	return (new);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	if (!s1)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	int		i;
	int		s_len;
	char	*new;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s) - start;
	if (s_len < len)
		len = s_len;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (s[start + i] && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strchr(char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (FALSE);
		s++;
	}
	return (TRUE);
}

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		*ptr++ = (unsigned char)c;
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isint(long long n)
{
	return (n >= -2147483648 && n <= 2147483647);
}

int	ft_catoi(const char *str)
{
	long long	next;
	long long	temp;
	int			sign;

	sign = 1;
	temp = 0;

	while (ft_iswhitespace(*str))
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (ft_isdigit(*str))
	{
		next = temp * 10 + sign * (*str - '0');
		if (!ft_isint(next))
			return (-1);
		temp = next;
		str++;
	}
	if (*str && (*str != '\n' && ft_isdigit(*str) == FALSE))
		return (-1);
	return ((int)temp);
}

int	ft_isempty(char *line)
{
	int	i;

	i = -1;
	while (line[++i] && line[i] != '\n')
		if (!ft_iswhitespace(line[i]))
			return (0);
	return (1);
}
