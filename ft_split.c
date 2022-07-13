/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:33 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:33 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_realloc_array_ptr(char **ptr, size_t new_size)
{
	char	**res;
	size_t	i;

	res = malloc(sizeof(char*) * new_size);
	i = 0;
	while (i < new_size)
	{
		res[i] = ptr[i];
		i++;
	}
	// TODO
	free(ptr);
	return (res);
}

static void	init_var(int *i, int *new_word, int *word_count, char ***res)
{
	*i = 0;
	*new_word = 1;
	*word_count = -1;
	*res = malloc(sizeof(char*));
	*res[0] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		new_word;
	int		word_count;

	init_var(&i, &new_word, &word_count, &res);
	if(ft_strlen(s) == 0)
		return (res);
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		else if (new_word && s[i] != c)
		{
			word_count++;
			res = ft_realloc_array_ptr(res, sizeof(char*) * (word_count + 1));
			new_word = 0;
			res[word_count] = ft_strjoin("", ft_char_to_str(s[i]));
		}
		else
			res[word_count] = ft_strjoin(res[word_count], ft_char_to_str(s[i]));
		i++;
	}
	res[word_count + 1] = NULL;
	return (res);
}
