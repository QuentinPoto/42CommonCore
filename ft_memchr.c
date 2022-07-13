#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	unsigned char 	*cstr;
	unsigned char 	cc;

	cstr = (unsigned char*)str;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cstr[i] == cc)
			return (&cstr[i]);
		i++;
	}
	return (NULL);
}