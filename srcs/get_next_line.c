#include "../inc/cub3D.h"

static char	*ft_read(int fd, char *buffer, char *backup)
{
	int		byte;
	char	*temp;

	while (1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (0);
		else if (byte == 0)
			break ;
		buffer[byte] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_extract(char *line)
{
	int		i;
	char	*output;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	output = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!output)
		return (NULL);
	if (output[0] == '\0')
	{
		free(output);
		output = NULL;
	}
	line[i + 1] = '\0';
	return (output);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_read(fd, buffer, backup);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		if (backup)
			free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = ft_extract(line);
	return (line);
}
