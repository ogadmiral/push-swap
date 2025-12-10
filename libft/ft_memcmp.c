/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:25:48 by mdamouh           #+#    #+#             */
/*   Updated: 2025/10/21 15:36:41 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s2tmp;
	unsigned char	*s1tmp;

	s1tmp = (unsigned char *) s1;
	s2tmp = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*(s1tmp + i) != *(s2tmp + i))
			return (*(s1tmp + i) - *(s2tmp + i));
		i++;
	}
	return (0);
}
