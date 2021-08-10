#include "get_next_line.h"
#include <stdio.h>

char	*trim(char **str)
{
	int		i;
	char	*trim;
	char	*temp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i] || (*str)[i] == '\n' && i == 1)
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
		*str = ft_strdup(temp);
		free(temp);
	}
	return (trim);
}

char	*get_next_line(int fd)
{
	static char	*str_left;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			n_bytes_rd;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	while (n_bytes_rd > 0)
	{
		buff[n_bytes_rd] = '\0';
		if (!str_left)
			str_left = ft_calloc(1, sizeof(char));
		temp = ft_strdup(str_left);
		free(str_left);
		str_left = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(str_left, '\n'))
			break ;
		n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	}
	// printf("here: %d, bytes: %d\n", !*str_left, n_bytes_rd);
	if (n_bytes_rd < 0 || (n_bytes_rd == 0 && !str_left))
		return (NULL);
	return (trim(&str_left));
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