#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (!c)
		return ((char *) s);
	return (NULL);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nelem * elsize);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nelem * elsize)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*trim(char **str)
{
	int		i;
	char	*trim;
	char	*temp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
	{
		trim = ft_strdup(*str);
		free(*str);
		*str = 0;
	}
	else
	{
		trim = ft_substr(*str, 0, i + 1);
		temp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = 0;
		if (*temp)
			*str = ft_strdup(temp);
		free(temp);
	}
	return (trim);
}

char	*get_next_line(int fd)
{
	static char	*fd_arr[1024];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			n_bytes_rd;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	while (n_bytes_rd > 0)
	{
		buff[n_bytes_rd] = '\0';
		if (!fd_arr[fd])
			fd_arr[fd] = ft_calloc(1, sizeof(char));
		temp = ft_strdup(fd_arr[fd]);
		free(fd_arr[fd]);
		fd_arr[fd] = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(fd_arr[fd], '\n'))
			break ;
		n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	}
	if (n_bytes_rd < 0 || (n_bytes_rd == 0 && !fd_arr[fd]))
		return (NULL);
	return (trim(&(fd_arr[fd])));
}
