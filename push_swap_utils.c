/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:13:40 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/29 15:05:37 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_inchunk(int index, int start, int end)
{
	if (index >= start && index <= end)
		return (1);
	return (0);
}

int	count_inchunk(t_stack *stack, int start, int end)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (is_inchunk(stack->index, start, end))
			count++;
		stack = stack->next;
	}
	return (count);
}

int	get_max(t_stack *stack)
{
	int	max;
	int	is_first;

	is_first = 1;
	while (stack)
	{
		if (is_first)
		{
			max = stack->index;
			is_first = 0;
		}
		if (stack->index >= max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_stack	*a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_repeated(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
