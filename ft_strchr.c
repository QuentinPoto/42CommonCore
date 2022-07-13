#include "libft.h"

char *ft_strchr(char *str, int c)
{
	while(*str)
	{
		if (*str == (unsigned char)c)
			return(str);
		str++;
	}
	if (*str == (unsigned char)c)
		return(str);
	return (NULL);
}
