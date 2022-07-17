//
// Created by quent on 7/17/2022.
//
#include "stdlib.h"

char	*add_modulo(int n)
{
	char	*res;
	int 	i;

	n /= 2;
	res = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		res[i] = '%';
		i++;
	}
	res[i] = 0;
	return (res);
}
