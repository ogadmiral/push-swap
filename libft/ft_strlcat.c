/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:55:07 by mdamouh           #+#    #+#             */
/*   Updated: 2025/10/24 16:31:08 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	if (size == 0 || (!dst && size == 0))
		return (ft_strlen(src));
	res = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (dst[i] != '\0' && i >= size)
		return (size + ft_strlen(src));
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
