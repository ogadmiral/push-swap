/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:30:15 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/03 18:13:00 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*negative_nbr(int n)
{
	int		count;
	char	*str;

	count = count_nbr(n) + 2;
	str = malloc(count);
	if (!str)
		return (NULL);
	str[count - 1] = '\0';
	count--;
	while (count > 1)
	{
		str[count - 1] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;

	count = count_nbr(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (negative_nbr(-n));
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (count > 0)
	{
		str[count - 1] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (str);
}
