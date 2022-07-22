#include "stdlib.h"
#include "libft.h"

void	ft_strrev(char *string)
{
	char	*temp;
	int	len;
	int	i;

	len = ft_strlen(string);
	temp = malloc(len + 1);
	i = 0;
	while(string[i])
	{
		temp[i] = string[len - i - 1];
		i++;
	}
	i = 0;
	while(i < len)
	{
		string[i] = temp[i];
		i++;
	}
	free(temp);
}

