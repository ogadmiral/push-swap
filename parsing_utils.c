/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:04 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/05 20:38:16 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *av)
{
	int	i;

	if (!av)
		return (0);
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

void	array_frier(char	**nums)
{
	int	i;

	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums[i]);
	free(nums);
}

int	is_only_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	len_digits(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		i++;
	}
	return (count);
}
