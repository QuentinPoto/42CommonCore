/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:43 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:43 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_until(const char *string, const char *charset)
{
	int		len;

	len = 0;
	while (string[len] && !ft_is_in_charset(string[len], charset))
		len++;
	return (len);
}
