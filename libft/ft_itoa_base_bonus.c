
#include "libft.h"

static int	count_char(unsigned long long int n, unsigned int n_base)
{
	int	res;

	res = 0;
	while (n)
	{
		n /= n_base;
		res++;
	}
	return (res);
}

char	*ft_itoa_base(unsigned long long int n, char *base, unsigned int n_base)
{
	char		*res;
	unsigned int	i;

	if (n == 0)
		return (ft_strdup("0"));
	res = malloc(count_char(n, n_base) + 2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (n)
	{
		res[i] = base[n % n_base];
		n /= n_base;
		i++;
	}
	res[i] = 0;
	ft_strrev(res);
	return (res);
}
