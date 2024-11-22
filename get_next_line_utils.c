#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stash || !buffer)
		return (NULL);
	temp = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!temp)
		return (NULL);
	while (stash[i])
	{
		temp[i] = stash[i];
		i++;	
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	return (temp);
}

int	stash_len(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strchr(char *buffer, int c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == (char)c)
			return ((char *)buffer + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(buffer + i));
	return (NULL);
}

char	*extract_line(char *stash)
{
	int	i;
	int	total_stash;
	int	total_line;
	char	*new_line;

	i = 0;
	total_stash = ft_strlen(stash);
	total_line = stash_len(stash);
	new_line = malloc(total_stash - total_line + 1);
	if (!new_line)
		return (NULL);
	while (stash[total_line + i])
	{
		new_line[i] = stash[total_line + i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
