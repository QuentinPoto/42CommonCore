/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:00:16 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/14 11:00:16 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char		*str_a;
	char		*str_b;
	size_t		i;

	str_a = (char *)str1;
	str_b = (char *)str2;
	i = 0;
	while (i < n)
	{
		if (str_a[i] > str_b[i])
			return (-1);
		if (str_a[i] < str_b[i])
			return (1);
		i++;
	}
	return (0);
}
