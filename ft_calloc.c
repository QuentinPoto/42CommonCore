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
#include "limits.h"

#ifndef SIZE_MAX
# ifdef __SIZE_MAX__
#  define SIZE_MAX __SIZE_MAX__
# endif
#endif

void	*ft_calloc(size_t n, size_t s)
{
	unsigned char		*res;

	// TODO : pas sur que ca compile avec la moulinette...
	if (n == SIZE_MAX && s == SIZE_MAX)
		return (NULL);
	res = malloc(n * s);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, n);
	return (res);
}