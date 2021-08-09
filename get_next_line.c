#include "get_next_line.h"

char	*trim(char **str)
{
	int		i;
	char	*trimmed;
	
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	trimmed = malloc(i + 2);
	ft_strlcpy(trimmed, (*str), i+2);
	*str = ft_strdup(&(*str)[i+1]);
	return (trimmed);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char		buff[BUFFER_SIZE];
	int			read_buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!store_str)
		store_str = malloc(BUFFER_SIZE + 1);
	if(!store_str)
		return (NULL);
	read_buff = read(fd, buff, BUFFER_SIZE);
	if (read_buff < 0)
		return (NULL);
	while (read_buff > 0)
	{
		if (read_buff < 0)
			return (NULL);
		store_str = ft_strjoin(store_str, buff);
		read_buff = read(fd, buff, BUFFER_SIZE);
	}
	return trim(&store_str);
}

// #include <stdio.h>
// int main()
// {
// 	int fd = open("file", O_RDWR);
// 	printf("%d\n", fd);
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		printf("%s", get_next_line(1000));
// 		// get_next_line(fd);
// 		i++;
// 	}
// 	return (0);
// }