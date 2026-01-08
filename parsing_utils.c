/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:04 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/08 11:40:51 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	handle_overflow(int sign, long *result, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		*result = (*result) * 10 + (s[i] - '0');
		if ((sign == 1 && (*result) > 2147483647))
			return (0);
		if ((sign == -1 && sign * (*result) < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split, int *numbers)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(numbers);
	error_exit();
}
