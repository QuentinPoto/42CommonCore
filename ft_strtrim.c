/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:54 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:54 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	i;
	unsigned int	len;
	char			*res;

	start = 0;
	while (ft_is_in_charset(s1[start], set))
		start++;
	len = ft_strlen_until(&s1[start], set);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (!ft_is_in_charset(s1[start], set) && s1[start])
	{
		res[i] = s1[i];
	}
	return (res);
}
/*
 * #1.  The string to be trimmed.
 * #2.  The reference set of characters to trim.Return value

 * The trimmed string.  NULL if the allocation fails.

 * Description : Allocates (with malloc(3)) and returns
 * a copy of’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string
 */