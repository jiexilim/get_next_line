#include "get_next_line.h"
// #include <stdio.h>
char	*trim(char **str)
{
	int		i;
	char	*trimmed;
	if (!*str || !(**str))
	{
		free(*str);
		return (NULL);
	}
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	trimmed = malloc(i + 2);
	if (!trimmed)
	{
		free(trimmed);
		free(*str);
		return (NULL);
	}
	ft_strlcpy(trimmed, (*str), i+2);
	*str = ft_strdup(&(*str)[i+1]);
	return (trimmed);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		if (!store_str)
		{
			store_str = malloc(BUFFER_SIZE + 1);
			if(!store_str)
			{
				free(store_str);
				return (NULL);
			}
		}
		store_str = ft_strjoin(store_str, buff);
	}
	free(buff);
	return trim(&store_str);
}

// int main()
// {
// 	int fd = open("file", O_RDWR);
// 	int i = 0;
// 	while (i < 4)
// 	{
// 		printf("%s", get_next_line(fd));
// 		// get_next_line(fd);
// 		i++;
// 	}
// 	return (0);
// }