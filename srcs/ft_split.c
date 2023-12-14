#include "cub3D.h"

static char	*im_free(char **new, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(new[i]);
		i++;
	}
	return (0);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	max_len(char const *s, char c)
{
	size_t	m_len;
	size_t	i;

	i = 0;
	m_len = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || \
		(s[i] == c && s[i + 1] && s[i + 1] != c))
			m_len++;
		i++;
	}
	return (m_len);
}

static char	*mk_word(char const *s, char c, char **new, size_t idx)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (word_len(s, c) + 1));
	if (!word)
	{
		im_free(new, idx);
		return (0);
	}
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	j;

	new = (char **)malloc(sizeof(char *) * (max_len(s, c) + 1));
	if (!new)
		return (0);
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			new[j] = mk_word(s, c, new, j);
			if (!new[j++])
			{
				free(new);
				return (0);
			}
		}
		while (*s != c && *s)
			s++;
	}
	new[j] = 0;
	return (new);
}