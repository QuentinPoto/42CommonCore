#include "utils.h"
#include "../libft/libft.h"
#include "../ft_printf.h"

char	*formated(va_list args, t_format_type format_type, int *null_count)
{
	int		m_char;
	char	temp_flag[50]; // TODO suffisant ? (oui)

	ft_strlcpy(temp_flag, format_type.flag, ft_strlen(format_type.flag));
	free(format_type.flag);
	if (format_type.type == 'c')
	{
		m_char = va_arg(args, unsigned int);
		if (!m_char) (*null_count)++;
		return (ft_char_to_str(m_char));
	}
	if (format_type.type == 'd' || format_type.type == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (format_type.type == 's')
		return (ft_strdup(va_arg(args, char *)));

	return (0);
}

char	*get_format(char *string, va_list args, int *null_count)
{
	int			i;
	t_format_type		format_type;
	char			*end_word;
	char			*formated_word;

	i = 0;
	while (string[i] && !ft_is_in_charset(string[i], "csuipdxXfegn"))
		i++;
	format_type.type = string[i];
	format_type.flag = ft_strdup((char*)string);
	format_type.flag[i] = 0;
	end_word = ft_strdup((char*)&string[i + 1]);
	free(string);
	string = NULL;
	formated_word = formated(args, format_type, null_count);
	return (ft_strjoin_free(&formated_word, &end_word));
}
