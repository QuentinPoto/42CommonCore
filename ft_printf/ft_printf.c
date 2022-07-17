//
// Created by quent on 7/17/2022.
//

#include "ft_printf.h"
#include "stdarg.h"
#include "utils/utils.h"
#include "libft.h"

// TODO : mettre en bonus // free_split
void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		if (words[i])
			free(words[i]);
		i++;
	}
	free(words);
}

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int 		i;
	char 		*to_print;
	int			*formats;
	char		**words;
	int			null_count;
	int			res;

	null_count = 0;
	va_start(args, string);
	formats = format_list((char *)string);
	words = ft_split((char *)string, '%');
	i = 0;
	to_print = ft_strdup("");
	while (words[i])
	{
		/// ajoute les modulo
		if (formats[i] && formats[i] > 1)
			to_print = ft_strjoin_free(to_print, add_modulo(formats[i]));
		/// ajoute les formatages
		if (formats[i] && formats[i] % 2 != 0)
			to_print = ft_strjoin_free(to_print, get_format(words[i], args, &null_count));
//		/// ajoute les mots sans %format (genre le 1er, ou ceux juste avec 2 %%)
//		if (!formats[i] || !(formats[i] % 2))
//			to_print = ft_strjoin_free(to_print, words[i]);
		i++;
	}
	ft_putstr_fd(to_print, 1);
	res = ft_strlen(to_print) + null_count;
	va_end(args);
//	free_words(words);
	free(words);
	free(formats);
	free(to_print);
	return (res);
}
