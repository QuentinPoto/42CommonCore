#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char *str_a;
	char *str_b;

	str_a = (char *)str1;
	str_b = (char *)str2;
	return (ft_strncmp(str_a, str_b, n));
}