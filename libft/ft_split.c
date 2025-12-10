/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:18:20 by mdamouh           #+#    #+#             */
/*   Updated: 2025/10/29 09:16:58 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static void	*ft_free_all(char **split_arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(split_arr[i]);
	}
	free(split_arr);
	return (NULL);
}

static char	**ft_allocate_and_fill(char const *s, char c, char **res)
{
	const char	*word_start;
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_start = s;
			while (*s != c && *s)
				s++;
			res[i] = ft_substr(word_start, 0, s - word_start);
			if (!res[i])
				return (ft_free_all(res, i));
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_allocate_and_fill(s, c, res);
	return (res);
}
