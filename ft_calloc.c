/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:01 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:01 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
// TODO : pas sur que le laisser en int marche partout...
{
	int		*res;

	res = malloc(n * s);
	if (res == NULL)
		return (NULL);
	while (n > 0)
	{
		res[n - 1] = 0;
		n--;
	}
	return (res);
}