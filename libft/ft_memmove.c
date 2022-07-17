/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:59:40 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/14 10:59:40 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO : facon + clean pour eviter le overlapping :
//  commencer par la fin, si le pointeur est plus petit que l'autre...
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	char		*src_ptr;
	char		temp[5000];

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = src_ptr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = temp[i];
		i++;
	}
	return (dest);
}
