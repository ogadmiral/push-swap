/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:13 by mdamouh           #+#    #+#             */
/*   Updated: 2025/10/25 17:55:59 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	found;

	if (!big && len == 0)
		return (NULL);
	if ((!ft_strncmp(big, little, len) && (len >= ft_strlen(little)))
		|| !little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (little[j] == big[i])
		{
			found = i;
			while (big[i + j] == little[j] && (j + i) < len)
				j++;
		}
		if (j == ft_strlen(little))
			return ((char *)big + found);
		i++;
	}
	return (NULL);
}
