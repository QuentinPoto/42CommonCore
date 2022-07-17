/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:57 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:57 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO : si ca start apres, est-ce que je renvoie null ?
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			res_len;
	char			*res;
	unsigned int	i;

	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	res_len = ft_strlen(&s[start]);
	if (start > len)
		return (ft_strdup(""));
	if (res_len > len)
		res_len = len;
	res = malloc(sizeof(char) * (res_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < res_len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}
/*
 *
 * #1.  The string from which to create the substring.
 * #2.  The start index of the substring in the string’s’.
 * #3.  The maximum length of the substring.Return valueThe substring.
 */
/*
 * NULL if the allocation fails.
 *
 * Description : Allocates (with malloc(3)) and returns a substring from the
 * string ’s’.
 *
 * The substring begins at index ’start’ and is of maximum size ’len’
 *
 *
 */
