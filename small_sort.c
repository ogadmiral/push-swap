/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:14:46 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/30 16:23:44 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > z)
		ra(a);
	else if (y > z)
	{
		sa(a);
		ra(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_lenlst(*a) > 3)
	{
		if ((*a)->index <= 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (*b && (*b)->index == 0)
		sb(b);
	pa(b, a);
	pa(b, a);
}

void	small_sort(t_stack *stack, t_stack *stackb, int size)
{
	if (size == 2)
	{
		if (stack->index > stack->next->index)
			sa(&stack);
	}
	if (size == 3)
		sort_three(&stack);
	if (size <= 5)
		sort_five(&stack, &stackb);
}