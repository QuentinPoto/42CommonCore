#include "libft.h"

char* ft_strrchr(char* str, int c)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while(i <= len)
	{
		if (str[len - i] == (unsigned char)c)
			return(&str[len - i]);
		i++;;
	}
	return (NULL);
}
