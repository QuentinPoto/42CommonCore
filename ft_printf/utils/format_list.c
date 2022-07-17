#include "../libft.h"

// TODO : a cut quand dans libft
static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		new_word;
	int		word_count;

	i = 0;
	new_word = 1;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		else if (new_word && s[i] != c)
		{
			new_word = 0;
			word_count++;
		}
		i++;
	}
	return (word_count);
}


/// fonction qui renvoie une liste du nombre de % pour chaque mot
int	*format_list(char *string)
{
	int		i;
	int		j;
	int 	*res;

	res = ft_calloc(ft_count_words(string, '%') + 100, sizeof(int)); //TODO marge
	i = 0;
	while (ft_is_in_charset(string[i++], "%"))
		res[0]++;
	j = 1;
	while (string[i])
	{
		if (string[i] == '%')
		{
			while (ft_is_in_charset(string[i++], "%"))
				res[j]++;
			j++;
		}
		else
			i++;
	}
	return (res);
}
