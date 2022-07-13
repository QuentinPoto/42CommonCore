#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char 		*dest_ptr;
	char 		*src_ptr;
	// TODO : utiliser unsigned char ?
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}