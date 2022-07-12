/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:22:41 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 21:22:41 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	test_ft_strtrim(void)
{
	char	new[] = "   salut     a     a   ";
	char	*res1 = ft_strtrim(new, " ");
	char	*res2 = ft_strtrim(new, "sa ");
	char	*res3 = ft_strtrim(new, "salut ");

	printf("original : %s\n\n", new);
	printf("string '%s'\nlen : %d\n", res1, ft_strlen(res1));
	printf("string '%s'\nlen : %d\n", res2, ft_strlen(res2));
	printf("string '%s'\nlen : %d\n", res3, ft_strlen(res3));
}

int	main(void)
{
	test_ft_strtrim();
//	printf("is in : %d", ft_is_in_charset('c', "ccc"));
}
