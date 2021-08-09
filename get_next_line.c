#include "get_next_line.h"
// #include <stdio.h>
char	*trim(char **str)
{
	int		i;
	char	*trimmed;
<<<<<<< HEAD
	// char	*temp;
	
	if (!*str && !(**str))
=======
	if (!*str || !(**str))
	{
		free(*str);
<<<<<<< HEAD
>>>>>>> parent of 3180f02 (Update .c files)
=======
>>>>>>> parent of 3180f02 (Update .c files)
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
<<<<<<< HEAD
<<<<<<< HEAD
	// free(*str);
	// *str = temp;
=======
=======
>>>>>>> parent of 3180f02 (Update .c files)
	if (!trimmed)
		free(trimmed);
	if (!(*str))
		free(*str);
<<<<<<< HEAD
>>>>>>> parent of 3180f02 (Update .c files)
=======
>>>>>>> parent of 3180f02 (Update .c files)
	return (trimmed);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char		*buff;
<<<<<<< HEAD
<<<<<<< HEAD
	char		*temp;
=======
>>>>>>> parent of 3180f02 (Update .c files)
=======
>>>>>>> parent of 3180f02 (Update .c files)

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
// 	while (i < 2)
// 	{
// 		printf("%s", get_next_line(fd));
// 		// get_next_line(fd);
// 		i++;
// 	}
// 	return (0);
// }