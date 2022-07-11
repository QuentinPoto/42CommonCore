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

static char *char_to_str(char c)
{
	char	*res;

	res = malloc(2);
	res[0] = c;
	res[1] = 0;
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	ten_factor;
	unsigned int	to_add;
	unsigned int	un;

	un = n;
	res = char_to_str(0);
	if (n < 0)
	{
		un = -n;
		res = char_to_str('-');
	}
	ten_factor = 1000000000;
	while (ten_factor)
	{
		to_add = un / ten_factor;
		if (to_add || ft_strlen(res) > 1)
			res = ft_strjoin(res, char_to_str(to_add + 48));
		un -= to_add * ten_factor;
		ten_factor /= 10;
	}
	return (res);
}