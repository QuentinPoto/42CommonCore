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

static char	*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int	res_len;
	unsigned int	i;
	unsigned int	j;
	char			*res;

	res_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (res_len + 1));
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	free(s1);
	free(s2);
	return (res);
}

static char	**ft_realloc_array_ptr(char **ptr, int word_count)
{
	char	**res;
	int		i;


	res = malloc(sizeof(char*) * (word_count + 2));
	i = 0;
	while (i < word_count)
	{
		res[i] = ptr[i];
		i++;
	}
	res[i] = NULL;
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
			res = ft_realloc_array_ptr(res, word_count);
			new_word = 0;
			res[word_count] = ft_strjoin_free(ft_strdup(""), ft_char_to_str(s[i]));
		}
		else
			res[word_count] = ft_strjoin_free(res[word_count], ft_char_to_str(s[i]));
		i++;
	}
	return (res);
}
