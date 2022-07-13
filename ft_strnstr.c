#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	c;
	char	*h;

	h = (char*)haystack;
	if (ft_strlen(needle) == 0 || needle == haystack)
		return(h);
	i = 0;
	while(h[i] && i < n)
	{
		c = 0;
		while (h[i + c] && needle[c] && h[i + c] == needle[c] && i + c < n)
			c++;
		if ((int)c == ft_strlen(needle))
			return(&h[i]);
		i++;
	}
	return(NULL);
}
