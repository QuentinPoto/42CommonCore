//
// Created by quent on 7/17/2022.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

typedef struct s_format_type {
	char	type;
	char	*flag;
}	t_format_type;

int	ft_printf(const char *string, ...);


#endif //FT_PRINTF_FT_PRINTF_H
