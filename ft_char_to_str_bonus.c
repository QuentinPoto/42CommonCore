#include "libft.h"
char *ft_char_to_str(char c)
{
	char	*res;

	res = malloc(2);
	res[0] = c;
	res[1] = 0;
	return (res);
}