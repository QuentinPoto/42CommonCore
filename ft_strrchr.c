#include "libft.h"

char* ft_strrchr(char* str, int c)
{
	int	i;
	int	len;

	len = ft_strlen(str) - 1;
	i = 0;
	while(i < len)
	{
		if (str[len - i] == c)
			return(str);
		i++;;
	}
	return (NULL);
}
