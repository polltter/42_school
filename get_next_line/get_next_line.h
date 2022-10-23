#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd);
size_t	size_until_nl(char *s);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	change_size(void **line, int old_size, int new_size);

#endif