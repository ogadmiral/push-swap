/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:18:20 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/08 10:17:56 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

int	count_words(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (ft_is_space(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_is_space(s[i]))
			i++;
	}
	return (count);
}

int	count_total_numbers(int argc, char **argv)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		total += count_words(argv[i]);
		i++;
	}
	return (total);
}

static char	*word_dup(char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	char	**arr;
	int		i;
	int		j;
	int		start;

	arr = malloc(sizeof(char *) * (count_words(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (ft_is_space(s[i]))
			i++;
		start = i;
		while (s[i] && !ft_is_space(s[i]))
			i++;
		if (start < i)
			arr[j++] = word_dup(s, start, i);
	}
	arr[j] = NULL;
	return (arr);
}
