#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char *str_a;
	char *str_b;

	str_a = (char *)str1;
	str_b = (char *)str2;

	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str_a[i] > str_b[i])
			return (-1);
		if (str_a[i] < str_b[i])
			return (1);
		i++;
	}
	return (0);
}