/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:51:56 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:51:56 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	long int	result;
	int			i;
	int			minus;

	result = 0;
	i = 0;
	minus = 1;
	while (ft_is_in_charset(string[i], " \t\n\r\v\f"))
		i++;
	if (string[i] == '-')
	{
		minus = -minus;
		i++;
	}
	else if (string[i] == '+')
		i++;
	while (ft_is_in_charset(string[i], "0123456789"))
	{
		result = result * 10 + string[i] - 48;
		i++;
	}
	return ((int)result * minus);
}
