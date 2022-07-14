/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:59:33 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/14 10:59:33 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO : utiliser unsigned char ?
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	char		*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
