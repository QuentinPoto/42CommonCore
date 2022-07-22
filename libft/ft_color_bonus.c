#include "libft.h"


void	ft_color(int color, int font)
{
	if (color == RESET)
		printf("\033[0m");
	if (color == RED)
		printf("\033[0;31m");
	if (color == GREEN)
		printf("\033[0;32m");
	if (color == YELLOW)
		printf("\033[0;33m");
	if (color == BLUE)
		printf("\033[0;34m");
	if (color == PURPLE)
		printf("\033[0;35m");
	if (color == CYAN)
		printf("\033[0;36m");
	if (color == WHITE)
		printf("\033[0;37m");

	if (font == BOLD)
		printf("\033[1m");
}

