#include "ft_printf.h"
#include "stdarg.h"
#include "utils/utils.h"
#include "libft/libft.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
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
	format_type.i = 0;
	format_type.ccount = 0;
	format_type.first_null = -1;
	to_print = ft_strdup("");
	while (words[format_type.i])
	{
		/// ajoute les modulo
		if (formats[format_type.i] && formats[format_type.i] > 1)
		{
			to_add = add_modulo(formats[format_type.i]); 
			to_print = ft_strjoin_free(&to_print, &to_add, &format_type.ccount);
		}
		/// ajoute les formatages
		if (formats[format_type.i] && formats[format_type.i] % 2 != 0)
		{
			to_add = get_format(words[format_type.i], args, &format_type);
			to_print = ft_strjoin_free(&to_print, &to_add, &format_type.ccount);
			free(format_type.flag);
		}
		/// ajoute les mots sans %format (genre le 1er, ou ceux juste avec 2 %%)
		if (!formats[format_type.i] || !(formats[format_type.i] % 2))
			to_print = ft_strjoin_free(&to_print, &words[format_type.i], &format_type.ccount);
		format_type.i++;
	}
	if (formats[format_type.i] && formats[format_type.i] > 1)
	{
		to_add = add_modulo(formats[format_type.i]); 
		to_print = ft_strjoin_free(&to_print, &to_add, &format_type.ccount);
	}
	res = format_type.ccount + format_type.null_count; // TODO ptet faire une autre variable ??
	if (format_type.first_null != -1)
		to_print[format_type.first_null] = '\0';
	ft_putstr_fd(to_print, 1);
	va_end(args);
	free(words);
	free(formats);
	free(to_print);
	return (res);
}
