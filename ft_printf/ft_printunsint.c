/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:18:19 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/18 10:02:08 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_printunsint(n / 10);
		count += ft_printunsint(n % 10);
	}
	else
	{
		count += ft_putchar(n + '0');
	}
	return (count);
}
