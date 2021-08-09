#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (!s1)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
	{
		join[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		join[i++] = *s2;
		s2++;
	}
	join[i] = '\0';
	return (join);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!src)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}