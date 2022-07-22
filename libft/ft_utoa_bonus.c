
#include "libft.h"

static int	init_mal(char **res, unsigned int n, unsigned int *i)
{
	int		count;
	unsigned int	cn;

	cn = n;
	count = 0;
	while (cn)
	{
		cn /= 10;
		count++;
	}
	if (n == 0)
	{
		*res = ft_strdup("0");
		return (1);
	}
	*res = malloc(count + 2);
	if (*res == NULL)
		return (1);
	*i = 0;
	return (0);
}

char	*ft_utoa(unsigned int n)
{
	char		*res;
	unsigned int	ten_factor;
	unsigned int	to_add;
	unsigned int	i;
	int		flag;

	if (init_mal(&res, n, &i))
		return (res);
	flag = 0;
	ten_factor = 1000000000;
	while (ten_factor)
	{
		to_add = n / ten_factor;
		if (to_add || flag)
		{
			flag = 1;
			res[i] = to_add + 48;
			i++;
		}
		n -= to_add * ten_factor;
		ten_factor /= 10;
	}
	res[i] = 0;
	return (res);
}
