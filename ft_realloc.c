#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;
	(void)ptr;
	size_t	i;

	while (i < size)
	{
//		res[i] = ptr[i];
		i++;
	}
	res = malloc(size);
	return (res);
}