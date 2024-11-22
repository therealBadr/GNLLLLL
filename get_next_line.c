#include "get_next_line.h"

char	*read_line(int fd, char *stash)
{
	char	*buffer;
	char	*old_stash;
	int	bytes_read;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while ((bytes_read != 0) && (ft_strchr(stash, '\n') == NULL))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), buffer = NULL, NULL);
		buffer[bytes_read] = '\0';
		old_stash = stash;
		stash = ft_strjoin(stash, buffer);
		free(old_stash);
	}
	free(buffer);
	return (stash);
}

char	*get_line(char *stash)
{
	char	*line;
	int	i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	line = malloc(stash_len(stash) + 1);
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*modify_stash(char *stash, char *line)
{
	char	*temp;

	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	temp = extract_line(stash);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(stash);
	stash = temp;
	return (stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	if (!stash)
	{
		stash = (char *) malloc(1);
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	stash = read_line(fd, stash);
	line = get_line(stash);
	stash = modify_stash(stash, line);
	return (line);
}
