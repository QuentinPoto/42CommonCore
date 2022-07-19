#include "ft_printf.h"
#include "stdarg.h"
#include "utils/utils.h"
#include "libft/libft.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int 		i;
	char 		*to_print;
	int		*formats;
	char		**words;
	int		res;
	char		*to_add;
	t_format_type	format_type;

	format_type.null_count = 0;
	va_start(args, string);
	formats = format_list((char *)string);
	words = ft_split((char *)string, '%');
	i = 0;
	to_print = ft_strdup("");
	while (words[i])
	{
		/// ajoute les modulo
		if (formats[i] && formats[i] > 1)
		{
			to_add = add_modulo(formats[i]); 
			to_print = ft_strjoin_free(&to_print, &to_add);
		}
		/// ajoute les formatages
		if (formats[i] && formats[i] % 2 != 0)
		{
			to_add = get_format(words[i], args, &format_type);
			to_print = ft_strjoin_free(&to_print, &to_add);
			free(format_type.flag);
		}
		/// ajoute les mots sans %format (genre le 1er, ou ceux juste avec 2 %%)
		if (!formats[i] || !(formats[i] % 2))
			to_print = ft_strjoin_free(&to_print, &words[i]);
		i++;
	}
	if (formats[i] && formats[i] > 1)
	{
		to_add = add_modulo(formats[i]); 
		to_print = ft_strjoin_free(&to_print, &to_add);
	}

	ft_putstr_fd(to_print, 1);
	res = ft_strlen(to_print) + format_type.null_count;
	va_end(args);
	free(words);
	free(formats);
	free(to_print);
	return (res);
}
