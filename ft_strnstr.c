#include "libft.h"

static int  is_occurence(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_strnstr(char *s1, char *s2, size_t n)
{
	while(*s1)
	{
		if (is_occurence(s1, s2, n))
			return(s1);
		s1++;
	}
	return(NULL);
}