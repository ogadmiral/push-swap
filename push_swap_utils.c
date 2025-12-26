/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:13:40 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/26 17:30:05 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_inchunk(t_stack *stack, int start, int end)
{
	if (!stack)
		return (0);
	if (stack->index >= start && stack->index <= end)
		return (1);
	return (0);
}
