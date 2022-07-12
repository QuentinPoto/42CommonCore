#include "libft.h"

void	ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char 	*v;

	v = (char *)s;
	i = 0;
	while (i < n)
		v[i++] = c;
}