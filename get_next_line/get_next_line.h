#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 6

char	*get_next_line(int fd);
char	*read_copy(char *line, int fd);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strdup_until_nl(char *s);
char	*forward_line(char *line);
void	*ft_memcpy(void *dest, void *src, size_t n);

#endif