/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:14:47 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/20 10:43:38 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

char	*ft_convert2(unsigned int n)
{
	char	*hex;
	char	*hexdigits;
	int		size;

	hexdigits = "0123456789abcdef";
	if (n == 0)
	{
		hex = malloc(2);
		if (!hex)
			return (NULL);
		ft_strcpy(hex, "0");
		return (hex);
	}
	size = len(n);
	hex = malloc(len(n) + 1);
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (n > 0)
	{
		hex[size - 1] = hexdigits[n % 16];
		n /= 16;
		size--;
	}
	return (hex);
}

int	ft_printhex(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = ft_convert2(n);
	if (!hex)
		return (-1);
	count += ft_putstr(hex);
	free(hex);
	return (count);
}
