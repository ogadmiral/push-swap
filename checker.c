/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:24:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/28 14:31:23 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*stackb;

	stackb = NULL;
	stack = ft_parse(ac, av);
	if (!stack)
		return (ft_printf("Error\n"), 0);
}