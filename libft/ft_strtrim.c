/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:16 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/04 08:17:34 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isin(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_emptystr(void)
{
	char	*substr;

	substr = malloc(1);
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

static char	*ft_copy(char *substr, char const *s1, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		substr[i] = s1[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*substr;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_emptystr());
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isin(s1[start], set))
		start++;
	if (start > end)
		return (ft_emptystr());
	while (ft_isin(s1[end], set))
		end--;
	substr = malloc(end - start + 2);
	if (!substr)
		return (NULL);
	substr = ft_copy(substr, s1, start, end);
	return (substr);
}
