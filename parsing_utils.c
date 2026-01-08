/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:04 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/08 10:44:02 by mdamouh          ###   ########.fr       */
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

void	handle_overflow(int sign, long result)
{
	if ((sign == 1 && result > 2147483647))
		error_exit();
	if ((sign == -1 && sign * result < -2147483648))
		error_exit();
}
