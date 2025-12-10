/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:38:06 by mdamouh           #+#    #+#             */
/*   Updated: 2025/10/23 09:54:35 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	size_t	j;
	size_t	is_found;

	size = ft_strlen(s);
	is_found = 0;
	i = 0;
	while (i <= size)
	{
		if (s[i] == (unsigned char) c)
		{
			j = i;
			is_found = 1;
		}
		i++;
	}
	if (is_found)
		return ((char *) s + j);
	else
		return (NULL);
}
