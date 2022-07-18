#include "../ft_printf.h"
#include "../libft/libft.h"
#include "stdio.h"
#include "unistd.h"

void	printf_test(void)
{
	printf("\n\nprintf tests :\n\n");
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
//Lenovo ThinkPad X270 12" Core i5 2,4 GHz - SSD 128 Go - 4 Go AZERTY - Français
void	red(void)
{
	printf("\033[0;31m");
	printf("\e[1m");
}

void	green(void)
{
	printf("\033[0;32m");
	printf("\e[1m");
}

void	r_col(void)
{
	printf("\033[0m");
	printf("\e[m");
}



void	c_test(void)
{
	red();
	printf("bool : %d\n", ft_printf("salut ", '0') == printf("salut ", '0') );
	printf("bool : %d\n", ft_printf("%c\n", '0') == printf("%c\n", '0') );
	printf("bool : %d\n", ft_printf(" %c \n", '0') == printf(" %c \n", '0') );
	printf("bool : %d\n", ft_printf(" %c\n", '0' - 256) == printf(" %c\n", '0' - 256));
	printf("bool : %d\n", ft_printf("%c \n", '0' + 256) == printf("%c \n", '0' + 256));
	printf("bool : %d\n", ft_printf(" %c %c %c \n", ' ', ' ', ' ') == printf(" %c %c %c \n", ' ', ' ', ' '));
	printf("bool : %d\n", ft_printf(" %c %c %c \n", '1', '2', '3') == printf(" %c %c %c \n", '1', '2', '3'));
	
	green();
	printf("bool : %d\n", ft_printf("' %c %c %c '\n", 0, '1', '2') == printf("' %c %c %c '\n", 0, '1', '2'));
	printf("bool : %d\n", ft_printf(" %c %c %c \n", '0', 0, '1') == printf(" %c %c %c \n", '0', 0, '1'));
	r_col();
	printf("bool : %d\n", ft_printf("' %c %c %c '\n", '2', '1', 0) == printf("' %c %c %c '\n", '2', '1', 0));
}
int	pos = 1;
#define TEST(format, args...) \
			system("gcc tester/print_out.c -L. -lftprintf -L./libft -lft -o print_out -D P='"#format","#args"'"); \
			system("./print_out > file"); \
			fp = fopen("file", "r"); \
			fread(buffer, 1000, 1, fp); \
			\
			sprintf_res = malloc(ft_strlen(format) + 1); \
			cres = sprintf(sprintf_res, format, args); \
			mcres = ft_printf(format, args);\
			\
			if (cres == mcres) { green(); printf("%d.OK return ", pos); } \
			else { red(); printf("%d.KO return ! expected : %d\t got : %d\n", pos, cres, mcres);  } \
			if (!ft_strncmp(buffer, sprintf_res, cres)) { green(); printf("%d.OK print ", pos); } \
			else { red(); printf("%d.KO print ! expected : %s\t got : %s\n", pos, sprintf_res, buffer); }\
			\
			pos++; r_col();\
			free(sprintf_res);
			
			//ft_putstr_fd(buffer, 1); \
			//ft_putendl_fd(sprintf_res, 1); \
						
void	test_p(void)
{
	char	buffer[100] = "";
	FILE	*fp;
	char	*sprintf_res;
	int	cres;
	int	mcres;
	
	TEST("salut les poto %d %d", 5, 5);
}

int main() 
{
//	ft_printf("salut '%0.d' new '%%%%', '%c', '%%%d' '%s'\n", 4000, 'A', 5, "print string");
//	printf_test();
//	c_test();
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
