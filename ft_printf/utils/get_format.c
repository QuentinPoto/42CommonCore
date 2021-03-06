#include "utils.h"
#include "../libft/libft.h"
#include "../ft_printf.h"

/*

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

enum e_type {
	I,
	LI,
	LLI,
	U,
	LU,
	LLU,
}

char	*ft_spe_itoa(void *n, int type)
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
*/

enum e_bool {
	FALSE,
	TRUE,
	SUCCESS = 0,
	ERROR = 1,
};

static char	*add_space(t_format_type *format_type, char **string)
{
	char	*res;
	int	c;
	int	i;
	int	is_neg;

	i = 0;
	while (format_type->flag[i] && !ft_is_in_charset(format_type->flag[i], "-+0123456789"))
		i++;
	c = ft_atoi(&format_type->flag[i]);
	is_neg = FALSE;
	if (c < 0)
	{
		is_neg = TRUE;
		c = -c;
	}

	if (c == 0 || c - ft_strlen(*string) == 0)
		return (NULL);
	c -= ft_strlen(*string);
	res = malloc(c + 1);
	ft_memset(res, ' ', c);
	res[c] = '\0';
	if (is_neg)
		return (ft_strjoin_free(string, &res, NULL));
	else
		return (ft_strjoin_free(&res, string, NULL));
}

static char	*character(unsigned int val, t_format_type *format_type)
{
	char	*res;


	if ((char)val == '\0'/* && format_type->*/) // TODO : que si ya pas de 0
	{
		format_type->null_count++;
		if (format_type->first_null == -1)
			format_type->first_null = format_type->ccount;
	}
	char	*temp = ft_char_to_str(val);
	res = add_space(format_type, &temp);
	if (res)
		return (res);
	return (ft_char_to_str(val));
	
}
// TODO : je vais transformer le ft_utoa, en tout type de format (avec un ... ?)

static char	*integers(long long int val, t_format_type *format_type)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (format_type->flag[i])
	{
		if (format_type->flag[i] == 'l')
			l++;
		i++;
	}
	if (l == 0)
		return(ft_itoa((int)val));
	else if (l == 1)
		return(ft_itoa((long int)val));
	else if (l == 2)
		return(ft_itoa((long long int)val));
	return(NULL);
}

static char	*hexa(unsigned int val, t_format_type *format_type)
{
	if (format_type->type == 'X')
		return(ft_itoa_base(val, "0123456789ABCDEF", 16));
	else
		return(ft_itoa_base(val, "0123456789abcdef", 16));
}

static char	*pointers(void *val, t_format_type *format_type)
{
	(void)format_type;
	if (val == 0)
		return(ft_strdup("(nil)"));
	return(ft_itoa_base((unsigned long long int)val, "0123456789abcdef", 16));
}


static char	*formated(va_list args, t_format_type *format_type)
{
	if (format_type->type == 'c')
		return (character(va_arg(args, unsigned int), format_type));
	if (format_type->type == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	if (format_type->type == 'd' || format_type->type == 'i')
		return (integers(va_arg(args, long long int), format_type));
	if (format_type->type == 's')
		return (ft_strdup(va_arg(args, char *)));
	if (format_type->type == 'p')
		//return (pointers(va_arg(args, unsigned long long int), format_type));
		return (pointers(va_arg(args, void *), format_type));
	if (format_type->type == 'x' || format_type->type == 'X')
		return (hexa(va_arg(args, unsigned long long int), format_type));
		//return (hexa(va_arg(args, unsigned int), format_type));
	return (0);
}

static void	set_format_type(t_format_type *format_type)
{
	// TODO : set tout les parametres t_format_type pour les avoirs partout
}

char	*get_format(char *string, va_list args, t_format_type *format_type)
{
	int	i;
	char	*end_word;
	char	*formated_word;

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
	return (ft_strjoin_free(&formated_word, &end_word, NULL));
}
