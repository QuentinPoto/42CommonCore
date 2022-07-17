#include "ft_printf.h"
#include "stdio.h"

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
Lenovo ThinkPad X270 12" Core i5 2,4 GHz - SSD 128 Go - 4 Go AZERTY - Français

void	c_test(void)
{
	printf("bool : %d\n", ft_printf("salut ", '0') == printf("salut ", '0') );
//	printf("bool : %d\n", ft_printf("%c\n", '0') == printf("%c\n", '0') );
//	printf("bool : %d\n", ft_printf(" %c \n", '0') == printf(" %c \n", '0') );
//	printf("bool : %d\n", ft_printf(" %c\n", '0' - 256) == printf(" %c\n", '0' - 256));
//	printf("bool : %d\n", ft_printf("%c \n", '0' + 256) == printf("%c \n", '0' + 256));
//	printf("bool : %d\n", ft_printf(" %c %c %c \n", ' ', ' ', ' ') == printf(" %c %c %c \n", ' ', ' ', ' '));
//	printf("bool : %d\n", ft_printf(" %c %c %c \n", '1', '2', '3') == printf(" %c %c %c \n", '1', '2', '3'));
//
//	printf("bool : %d\n", ft_printf("' %c %c %c '\n", 0, '1', '2') == printf("' %c %c %c '\n", 0, '1', '2'));
//	printf("bool : %d\n", ft_printf(" %c %c %c \n", '0', 0, '1') == printf(" %c %c %c \n", '0', 0, '1'));
//	printf("bool : %d\n", ft_printf("' %c %c %c '\n", '2', '1', 0) == printf("' %c %c %c '\n", '2', '1', 0));
}
int main() {
//	ft_printf("salut '%0.d' new '%%%%', '%c', '%%%d' '%s'\n", 4000, 'A', 5, "print string");
//	printf_test();
	c_test();
	return 0;
}

/*
 type to handle :
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