
#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

typedef struct s_format_type {
	char	type;
	char	*flag;
	int	null_count;
	int	i;
}	t_format_type;

int	ft_printf(const char *string, ...);


#endif //FT_PRINTF_FT_PRINTF_H
