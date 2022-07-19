#include "../ft_printf.h"
#include "../libft/libft.h"
#include "stdio.h"
#include "unistd.h"

// TODO : dans libft 
enum e_font {
	RED,
	GREEN,
	WHITE,
	BLUE,
	YELLOW,
	PURPLE,
	STD,
	BOLD,
};
void	ft_color(int color, int font)
{
	if (color == WHITE)
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


	if (font == STD)	
		printf("\e[m");
	if (font == BOLD)	
       		printf("\e[1m");
}

#define TEST(format, args...) \
			ft_bzero(buffer, 100); \
			if (mode == 0) \
				system("gcc tester/print_out.c -L. -lftprintf -L./libft -lft -o print_out -DFORMAT='"#format"' -DARGS='"#args"'  "); \
			else \
				system("gcc tester/print_out.c -L. -lftprintf -L./libft -lft -o print_out -DFORMAT='"#format"' -DARGS=\""#args"\"  "); \
			system("./print_out > file"); \
			fp = fopen("file", "r"); \
			fread(buffer, 1000, 1, fp); \
			fclose(fp);\
			\
			sprintf_res = malloc(ft_strlen(format) + 10); \
			cres = sprintf(sprintf_res, format, args); \
			mcres = ft_printf(format, args);\
			printf("\r");\
			if (cres == mcres) {\
			       	ft_color(GREEN, BOLD); \
				printf("%4d.OK ", pos);\
		       	} \
			else { \
				ft_color(RED, BOLD); \
				printf("%4d.KO ! expected : %d\t got : %d\n", pos, cres, mcres);  \
			} \
			if (!ft_strncmp(buffer, sprintf_res, cres)) {\
			       	ft_color(GREEN, BOLD); \
				printf("%4d.OK : '%s' '%s' (%s)\n", pos, sprintf_res, buffer, ""#format", "#args"" ); \
			} \
			else { \
				ft_color(RED, BOLD); \
				printf("%4d.KO ! expected : '%s'\t got : '%s', (%s)\n", pos, sprintf_res, buffer, ""#format", "#args""); \
			} \
			\
			pos++; free(sprintf_res); system("rm -f file");
			
						
void	test_p(void)
{
	char	buffer[100];
	FILE	*fp;
	char	*sprintf_res;
	int	cres;
	int	mcres;
	int	pos;
	int	mode;

	ft_color(WHITE, BOLD); printf("\n   %-7s %-7s\n", "RETURN", "PRINT");	


	/// %c	
	pos = 1; mode = 1; ft_color(BLUE, BOLD); printf("\nCHAR (%%c)\n");
	TEST("salut ", '0');
	TEST("%c", '0');	
	TEST("  %c  ", '0');	
	TEST("%%%%%c  ", '0' - 256);	
	TEST("  %c  %%", '0' + 256);	
	TEST(" %c %c %c ", ' ', ' ', ' ');	
	TEST(" %c %c    %c", '1', '2', '3');	
	TEST("%c %c %c", 0, 0, 0); // TODO imprimme les espace (devrait tout compter et s'arreter au 1er 0 ??
	TEST("", ' ');

	/// %d
	pos = 1; mode = 2; ft_color(BLUE, BOLD); printf("\nINT (%%d) (%%i)\n");
	TEST("%%%d", 0);
	TEST("%d", 2093422345235243334);
	TEST("  %d   i   a   ", 404);
	TEST("%d     %d",560, 55);
	TEST("       %d", 1);
	TEST("%d", 0xF);
	TEST("%d uuuu uuuu ", 4834275098347592);
	TEST(" %d", 12);
	TEST(" %i", 12);
	TEST(" %i %%%%   , %d", 5464, 45);
	TEST(" %%%i     ", 16202);

	/// %s
	pos = 1; mode = 0; ft_color(BLUE, BOLD); printf("\nSTRING (%%s)\n");
	TEST("%s", "hi mom");
	TEST("%s     ", "hi mom");
	TEST("      %s", "hi mom");
	TEST("  %s   ", "hi mom");
	TEST("%s", "");
	TEST("%s ", "");
	TEST(" %s", "");
	TEST("   %s   ", "");

	/// %x %X
	pos = 1; mode = 5; ft_color(BLUE, BOLD); printf("\nHEXA (%%x) (%%X)\n");
	TEST("%X", 0xF);

	/// %p
	pos = 1; mode = 4; ft_color(BLUE, BOLD); printf("\nPOINTER (%%p)\n"); int val; int var;
	TEST("%p", &val);
	TEST("%p", NULL);

	/// %u
	pos = 1; mode = 6; ft_color(BLUE, BOLD); printf("\nUNSIGNED INT (%%u)\n");
	TEST("%u", 12);
	TEST("%u", -12);


	return ;	
	printf("'%10s'\n", "test");
	printf("'%*s'\n", -10, "test");
	printf("'%10.3s'\n", "12345");
	printf("'%10.*s'\n", 3, "12345");
	printf("'%-10s'\n", "test");
	printf("'% -10d'\n", 4);
	printf("'%010d'\n", 4);
	printf("'%10d'\n", 4);
	int printed = printf("'% .5f'\n", 4.1234);
	printf("'%d' printed !\n", printed);
	printf("\nje ne sais pas ce que le h change... : \n");
	char v = 'a';
	printf("char : '%hhi' printed !\n", v);
	printf("char : '%hi' printed !\n", v);
	short int c = 5;
	printf("char : '%i' printed !\n", c);
	printf("char : '%hi' printed !\n", c);
	int new = 0;
	printf("ptr '%n'\n", &new);
	printf("le vrai : %d\n", new);
	int s;
	printf("The value of %ns : ", &s);
	printf("%d", s);
}

int main() 
{
	test_p();
}

/*
 types to handle :
 ----------
 c		char
 s		string
 p		pointer
 d		Signed decimal integer
 i		Signed decimal integer (same as %d)
 u		Unsigned decimal integer
 x		hexa (a12)
 X		hexa (A12)
 %		Prints a percent sign
 bonus types :
 --------
 f		Floating-point number, decimal notation
 e		Floating-point number, e-notation
 g		Use %f or %e, depending on the value.
 		The %e style is used if the exponent is less
 		than -4 or greater than or equal to the precision.
 n		truc mistique qui charge la valeur, tres intrange...

 flags to handle :
 ----------
 0		Specifies that integer or floating-point values should be padded
 		with zeros instead of spaces to fill out the field width to the left

 -		Specifies that the output value is left justified in the output field and padded with blanks on the right.
		The default positioning of the output is right justified
 .
 *
 Bonus flags:
 -----------
 l		devant, long
 ll		devant, long long
 h		integer conversion specifier applies to a short or unsigned short argument (short int caca;)
 hh		integer conversion specifier applies to a signed char or unsigned char argument (short char caca;)

 #		Ensures that
		0 is to precede an octal output value.
		0x or 0X is to precede a hexadecimal output value.
		A floating-point output value will contain a decimal point.
		For g or G floating-point conversion characters, trailing zeros will not be omitted

 +		Ensures there's always a plus or minus sign preceding a signed output value.
		Only negative values have a sign by default

 ' ' 	(a space) Specifies that positive or zero values are preceded by a space rather than a plus sign


  f auth :
 ---------
 malloc
 free
 write
 va_start
 va_arg
 va_copy
 va_end
 + libft
*/
