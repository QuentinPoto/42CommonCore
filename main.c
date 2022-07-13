/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:22:41 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 21:22:41 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"
#include "limits.h"

void	test_ft_strtrim(void)
{
	char	new[] = "   salut     a     a   ";
	char	*res1 = ft_strtrim(new, " ");
	char	*res2 = ft_strtrim(new, "sa ");
	char	*res3 = ft_strtrim(new, "salut ");

	printf("original : %s\n\n", new);
	printf("string '%s'\nlen : %d\n", res1, ft_strlen(res1));
	printf("string '%s'\nlen : %d\n", res2, ft_strlen(res2));
	printf("string '%s'\nlen : %d\n", res3, ft_strlen(res3));
}

void	test_ft_bzero(void)
{
	char	*new = ft_strdup("true");
	printf("avant erase : '%s'\n", new);
	bzero(new, sizeof(char) * ft_strlen(new));
	printf("apres erase : '%s'\n", new);

	char	*new2 = ft_strdup("mine");
	printf("avant erase : '%s'\n", new2);
	ft_bzero(new2, sizeof(char) * ft_strlen(new2));
	printf("apres erase : '%s'\n", new2);
}

void	test_ft_memset(void)
{
	int c = 49;
	int i = 0;

	char	*new = ft_strdup("true");
	printf("avant erase : '%s'\n", new);
	memset(new, c, sizeof(char) * ft_strlen(new));
	printf("apres erase : '%s'\n", new);
	printf("apres erase : '%d'\n", new[i]);

	char	*new2 = ft_strdup("mine");
	printf("avant erase : '%s'\n", new2);
	ft_memset(new2, c, sizeof(char) * ft_strlen(new2));
	printf("apres erase : '%s'\n", new2);
	printf("apres erase : '%d'\n", new2[i]);
}

void	test_ft_split(int loop)
{
	char string1[] = "bonsoir, comment ca va ?";
	char string2[] = "             ";
	char string3[] = " s salut les potosse        f";

	char charset = ' ';

	char **res1 = ft_split(string1, charset);
	char **res2 = ft_split(string2, charset);
	char **res3 = ft_split(string3, charset);
	if (!loop)
		return;

	int i = 0;
	printf("\noriginal : %s\n", string1);
	while (res1[i-1])
	{
		printf("string %d : %s\n", i, res1[i]);
		i++;
	}
	printf("\noriginal : %s\n", string2);
	i = 0;
	while (i < 2)
	{
		printf("string %d : %s\n", i, res2[i]);
		i++;
	}

	i = 0;
	printf("\noriginal : %s\n", string3);
	while (res3[i-1])
	{
		printf("string %d : %s\n", i, res3[i]);
		i++;
	}
}

void	test_ft_realloc(void)
{
	char *string = ft_strdup("hello");

	printf("original : %s\n", string);


	string = ft_realloc(string, ft_strlen(string) + 10);
	printf("apres realloc : %s\n", string);

	string[7] = 'f';
	string[8] = 0;

	printf("apres modif : %s\n", string);

}

void	test_ft_memccpy(void)
{
	const char src[50] = "ce que nous voulons copier !";
	char dest[50];
	strcpy(dest,"Heloooo!!");
	printf("Vrai fonction : \nBefore = %s\n", dest);
	char *last = memccpy(dest, src, 'l', strlen(src)+1);
	*last = 0;
	printf("After = %s\n", dest);

	const char src2[50] = "ce que nous voulons copier !";
	char dest2[50];
	strcpy(dest2,"Heloooo!!");
	printf("\nMa fonction : \nBefore = %s\n", dest2);
	char *last2 = ft_memccpy(dest2, src2, 'l', strlen(src2)+1);
	*last2 = 0;
	printf("After = %s\n", dest2);
}

void	test_ft_memcpy(void)
{
	const char src[50] = "ce que nous voulons copier !";
	char dest[50];
	strcpy(dest,"Heloooo!!");
	printf("Vrai fonction : \nBefore = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After = %s\n", dest);

	const char src2[50] = "ce que nous voulons copier !";
	char dest2[50];
	strcpy(dest2,"Heloooo!!");
	printf("\nMa fonction : \nBefore = %s\n", dest2);
	ft_memcpy(dest2, src2, strlen(src2)+1);
	printf("After = %s\n", dest2);

	int len = 4;
	int i = 0;
	int testS1[] = {1,2,3,4};
	int testD1[] = {0,0,0,0};
	printf("\nint array : \n\nvrai fonction : \nBefore = %d\n", testD1[i]);
	memcpy(testD1, testS1, sizeof(int) * len);
	printf("After = %d\n", testD1[i]);

	int testS2[] = {1,2,3,4};
	int testD2[] = {0,0,0,0};
	printf("\nMa fonction : \nBefore = %d\n", testD2[i]);
	ft_memcpy(testD2, testS2, sizeof(int) * len);
	printf("After = %d\n", testD2[i]);
}

void	test_ft_memcmp(void)
{
	char *str1 = ft_strdup("salot");
	char *str2 = ft_strdup("salut");
	int 	n = 4;

	int ret = memcmp(str1, str2, n);
	int ret2 = ft_memcmp(str1, str2, n);

	printf("vrai fonction : %d\n", ret);
	printf("  ma fonction : %d\n", ret2);

}

void	test_ft_itoa(void)
{
	printf("\nresultats : \n\n");
	printf("-%15s\n", ft_itoa(INT_MAX));
	printf("-%15s\n", ft_itoa(INT_MIN));
	printf("-%15s\n", ft_itoa(-1));
	printf("-%15s\n", ft_itoa(1));
	printf("-%15s\n", ft_itoa(0));
}
void	test_ft_toupper(void)
{
	printf("%c\n", ft_toupper('z'+1));
	printf("%c\n", ft_tolower('z'));
}
int	main(void)
{
//	test_ft_strtrim();
//	test_ft_bzero();
//	test_ft_memset();
//	test_ft_split(1);
//	test_ft_realloc();
//	test_ft_memcpy();
//	test_ft_memccpy();
//	test_ft_memcmp();
	// test_ft_toupper();
	test_ft_itoa();

	return (0);
}

/*
KO


substr
strjoin 
strtrim 
split 
itoa 
strmapi 
strlcat 
strnstr
atoi 
memcmp 
strchr 
strrchr 
strncmp 
strlcpy 
calloc 
striteri
 */

