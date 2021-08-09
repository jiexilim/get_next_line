#include "get_next_line.h"
// #include <stdio.h>

char	*trim(char **str)
{
	int		i;
	char	*trimmed;
	char	*temp;
	
	if (!*str && **str)
	{	
		free(*str);
		return (NULL);
	}
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	trimmed = malloc(i + 2);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, (*str), i+2);
	temp = ft_strdup(&(*str)[i+1]);
	free(*str);
	if (!*temp)
		*str = temp;
	else
		free(temp);
	return (trimmed);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char		*buff;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
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
		temp = ft_strjoin(store_str, buff);
		free(store_str);
		store_str = temp;
	}
	free(buff);
	return (trim(&store_str));
}

// int main()
// {
// 	int fd = open("file", O_RDWR);
// 	int i = 0;
// 	while (i < 2)
// 	{
// 		printf("%s", get_next_line(fd));
// 		// get_next_line(fd);
// 		i++;
// 	}
// 	return (0);
// }