#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
char	*trim(char **str)
{
	int		i;
	char	*trimmed;
	char	*temp;
	
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
	{
		trimmed = ft_strdup(*str);
		return (trimmed);
	}
	// trimmed = malloc(i + 2);
	// if (!trimmed)
	// 	return (NULL);
	// ft_strlcpy(trimmed, (*str), i+2);	
	trimmed = ft_substr(*str, 0, i + 1);
	ft_strlen(*str + i + 1);
	temp = ft_strdup(*str + i + 1);
	free(*str);
	if (temp[0] != '\0')
		*str = temp;
	else
		free(temp);
	return (trimmed);
}

char*get_next_line(int fd)
{
	static char	*store_str;
	char		*buff;
	char		*temp;
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[rd] = '\0';
		if (!store_str)
		{
			store_str = malloc(BUFFER_SIZE + 1);
			if(!store_str)
			{
				free(store_str);
				return (NULL);
			}
			store_str[0] = '\0';
		}
		temp = ft_strjoin(store_str, buff);
		free(store_str);
		store_str = temp;
		rd = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (trim(&store_str));
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