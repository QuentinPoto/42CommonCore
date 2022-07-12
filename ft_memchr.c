#include "libft.h"

/// c'est comme un str str... mais avec juste un character
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char 	*cstr;

	cstr = (char *)str;
	i = 0;
	while (i < n && cstr[i])
	{
		if (cstr[i] == c)
			return (&cstr[i]);
		i++;
	}
	return (NULL);
}