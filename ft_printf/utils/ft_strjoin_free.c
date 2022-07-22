#include "../libft/libft.h"

char	*ft_strjoin_free(char **s1, char **s2, int *ccount)
{
	char			*res;

	res = ft_strjoin(*s1, *s2);
	if (ccount)
		*ccount = ft_strlen(res);
	free(*s1);
	*s1 = NULL;
	free(*s2);
	*s2 = NULL;
	return (res);
}
