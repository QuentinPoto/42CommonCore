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
// TODO : pas sur que ca compile avec la moulinette...
//		le test du gars avec size max fait crash, comment gerer, en sachant
//		que le size max change partout...

#ifndef SIZE_MAX
# ifdef __SIZE_MAX__
#  define SIZE_MAX __SIZE_MAX__
# endif
#endif

void	*ft_calloc(size_t nmem, size_t size)
{
	unsigned char		*res;

	if (nmem == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	res = malloc(nmem * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, (nmem * size));
	return (res);
}
