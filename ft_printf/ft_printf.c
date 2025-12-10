/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:54:58 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/20 11:24:37 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handlespc(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x')
		return (ft_printhex(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_printuphex(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_printaddress(va_arg(args, unsigned long)));
	else if (c == 'u')
		return (ft_printunsint(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_handlespc(format[i + 1], args);
			i += 2;
		}
		else
		{
			if (format[i] == '%' && !format[i + 1])
				return (-1);
			count += write(1, &format[i++], 1);
		}
	}
	va_end(args);
	return (count);
}
