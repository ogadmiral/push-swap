/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:30:58 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/20 10:43:02 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert(unsigned long n)
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

int	ft_printaddress(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	if (n == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += write(1, "0x", 2);
	hex = ft_convert(n);
	if (!hex)
		return (-1);
	count += ft_putstr(hex);
	free(hex);
	return (count);
}
