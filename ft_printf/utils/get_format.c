#include "utils.h"
#include "../libft/libft.h"
#include "../ft_printf.h"


static char	*character(unsigned int val, t_format_type *format_type)
{
	if (!val) 
	{
		format_type->null_count++;
		// TODO : comment lui dire que si c'est au debut il devrait cut le reste de la string !!
		// 
	}
	return (ft_char_to_str(val));
	
}

static char	*pointers(unsigned int val, t_format_type *format_type)
{
	// TODO : blabla...
	(void)val;
	(void)format_type;
	return(ft_strdup("caca"));
}

static char	*formated(va_list args, t_format_type *format_type)
{
	if (format_type->type == 'c')
		return (character(va_arg(args, unsigned int), format_type));
	if (format_type->type == 'd' || format_type->type == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (format_type->type == 's')
		return (ft_strdup(va_arg(args, char *)));
	if (format_type->type == 'x' || format_type->type == 'X')
		return (pointers(va_arg(args, unsigned int), format_type));
	return (0);
}

char	*get_format(char *string, va_list args, t_format_type *format_type)
{
	int			i;
	char			*end_word;
	char			*formated_word;

	i = 0;
	while (string[i] && !ft_is_in_charset(string[i], "csuipdxXfegn"))
		i++;
	format_type->type = string[i];
	format_type->flag = ft_strdup((char*)string);
	format_type->flag[i] = 0;
	end_word = ft_strdup((char*)&string[i + 1]);
	free(string);
	string = NULL;
	formated_word = formated(args, format_type);
	return (ft_strjoin_free(&formated_word, &end_word));
}
