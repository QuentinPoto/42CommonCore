
#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

typedef struct s_format_type {
	char	type;		// lettre apres le %
	char	*flag;	// entre le % et le type
	int	null_count;	// le nombre de %c == \0
	int	i;		// index dans la splited list
	int	first_null;	// index dans le mot du premier \0
	int	ccount;	// compte les char (i du mot final)
	
	int	zero;		// bool, flag 0
	int	left_pad;	// bool, flag -
	int	point;	// bool, flag .



}	t_format_type;

int	ft_printf(const char *string, ...);


#endif //FT_PRINTF_FT_PRINTF_H


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

 flags to handle :
 ----------
 0		Specifies that integer or floating-point values should be padded
 		with zeros instead of spaces to fill out the field width to the left

 -		Specifies that the output value is left justified in the output field and padded with blanks on the right.
		The default positioning of the output is right justified
 .		pour les float ?
 *		pour changer, mais je vais en chier du coup
 
 */


