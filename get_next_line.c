#include "get_next_line.h"

char	*trim(char **str)
{
	int		i;
	char	*trimmed;
	
	i = 0;
	while ((*str)[i] != '\n')
		i++;
	trimmed = malloc(i + 1);
	ft_strlcpy(trimmed, (*str), i);
	return (trimmed);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char		buff[BUFFER_SIZE];
	int			read_buff;

	store_str = malloc(BUFFER_SIZE);
	read_buff = read(fd, buff, BUFFER_SIZE);
	while (read_buff > 0)
	{
		if (read_buff < 0)
			return (NULL);
		store_str = ft_strjoin(store_str, buff);
		read_buff = read(fd, buff, BUFFER_SIZE);
	}
	return trim(&store_str);
}

#include <stdio.h>
int main()
{
	int fd = open("file.txt", O_RDONLY);
	int i;
	while (1)
	{
		printf("%s", get_next_line(fd));
		break ;
	}
	return (0);
}