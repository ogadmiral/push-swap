/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:04 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/05 18:44:05 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) || av[i] == ' ' || av[i] == '-' || av[i] == '+')
		{
			if ((av[i] == '-' || av[i] == '+') && (!ft_isdigit(av[i + 1])
					|| (i != 0 && av[i - 1] != ' ')))
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}
