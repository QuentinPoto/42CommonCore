/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:21 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:21 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INT_MIN -2147483648
// TODO : probleme avec les tests cpp, mais je pense que ca viens d'eux...
static int	count_char(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		n = -n;
		res++;
	}
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	ten_factor;
	unsigned int	to_add;
	unsigned int	un;
	unsigned int	i;
	int				flag;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	res = malloc(sizeof(char) * (count_char(n) + 1));
	if (res == NULL)
		return(NULL);

	i = 0;
	if (n < 0)
	{
		n = -n;
		res[i++] = '-';
	}
	un = n;
	flag = 0;
	ten_factor = 1000000000;
	while (ten_factor)
	{
		to_add = un / ten_factor;
		if (to_add || flag)
		{
			flag = 1;
			res[i] = to_add + 48;
			i++;
		}
		un -= to_add * ten_factor;
		ten_factor /= 10;
	}
	res[i] = 0;
	return (res);
}
