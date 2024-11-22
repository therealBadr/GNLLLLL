#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *stash);
char	*ft_strchr(char *buffer, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *stash, char *buff);
int		stash_len(char *stash);
char	*extract_line(char *stash);
char	*get_line(char *stash);
char	*modify_stash(char *stash, char *line);

#endif

