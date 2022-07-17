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

// TODO : turn public for ft_printf
//  bonus !
static char	*ft_strjoin_free(char *s1, char s2)
{
	char			*res;
	char			*s2_c;

	s2_c = ft_char_to_str(s2);
	res = ft_strjoin(s1, s2_c);
	free(s1);
	free(s2_c);
	return (res);
}

// TODO : turn public for ft_printf
//  bonus !
static int	count_words(char const *s, char c)
{
	int		i;
	int		new_word;
	int		word_count;

	i = 0;
	new_word = 1;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		else if (new_word && s[i] != c)
		{
			new_word = 0;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

static void	init_vars(int *i, int *new_word, int *word_count)
{
	*i = 0;
	*new_word = 1;
	*word_count = -1;
}

static int	init_res(char const *s, char c, int *n_word, char ***res)
{
	*n_word = count_words(s, c);
	*res = ft_calloc((*n_word) + 1, sizeof(char *));
	if (*res == NULL)
		return (1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		new_word;
	int		word_count;
	int		n_word;

	init_vars(&i, &new_word, &word_count);
	if (init_res(s, c, &n_word, &res))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		else if (new_word && s[i] != c)
		{
			new_word = 0;
			res[++word_count] = ft_strjoin_free(ft_strdup(""), s[i]);
		}
		else
			res[word_count] = ft_strjoin_free(res[word_count], s[i]);
		if (word_count > n_word && res[word_count] == NULL)
			return (NULL);
		i++;
	}
	return (res);
}
