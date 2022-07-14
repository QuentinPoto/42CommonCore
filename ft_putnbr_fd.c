/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:28 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:28 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*ascii;

	ascii = ft_itoa(n);
	ft_putstr_fd(ascii, fd);
	free(ascii);
}
// TODO : g pas le droit de free...
/*
#include "libft.h"
#define INT_MIN -2147483648

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

static int	init_mal(char **res, int *n, unsigned int *i)
{
	if (*n == 0)
	{
		*res = ft_strdup("0");
		return (1);
	}
	if (*n == INT_MIN)
	{
		*res = ft_strdup("-2147483648");
		return (1);
	}
	*res = malloc(sizeof(char) * (count_char(*n) + 1));
	if (*res == NULL)
		return (1);
	*i = 0;
	if (*n < 0)
	{
		*n = -(*n);
		*res[(*i)++] = '-';
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	ten_factor;
	unsigned int	to_add;
	unsigned int	i;
	int				flag;

	if (init_mal(&res, &n, &i))
		return (res);
	flag = 0;
	ten_factor = 1000000000;
	while (ten_factor)
	{
		to_add = n / ten_factor;
		if (to_add || flag)
		{
			flag = 1;
			res[i] = to_add + 48;
			i++;
		}
		n -= to_add * ten_factor;
		ten_factor /= 10;
	}
	res[i] = 0;
	return (res);
}
*/