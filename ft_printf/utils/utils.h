//
// Created by quent on 7/15/2022.
//

#ifndef FT_PRINTF_UTILS_H
#define FT_PRINTF_UTILS_H
# include "stdarg.h"
# include "../ft_printf.h"

int	*format_list(char *string);
char	*ft_strjoin_free(char **s1, char **s2);
char	*add_modulo(int n);
char	*get_format(char *string, va_list args, t_format_type *format_type);

#endif //FT_PRINTF_UTILS_H
