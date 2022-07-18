#include "../ft_printf.h"
#include "stdio.h"
#include "../libft/libft.h"

#ifndef P
# define P "ERREUR, pas de define...  %d \n", 5
#endif


int	main(void)
{	
	ft_printf(P);
}

