/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:46:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/29 15:10:04 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack	*stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		else
			pos++;
		stack = stack->next;
	}
	return (pos);
}

void	ft_buildb(t_stack **stacka, t_stack **stackb)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = get_chunk_size(ft_lenlst(*stacka));
	while (*stacka)
	{
		if ((*stacka)->index <= i)
		{
			pb(stacka, stackb);
			rb(stackb);
			i++;
		}
		else if ((*stacka)->index <= i + chunk)
		{
			pb(stacka, stackb);
			i++;
		}
		else
			ra(stacka);
	}
}

void	ft_build_fromb(t_stack	**stackb, t_stack **stacka)
{
	int	max;
	int	pos;

	while (*stackb)
	{
		max = get_max(*stackb);
		if ((*stackb)->index == max)
			pa(stackb, stacka);
		else
		{
			pos = get_position(*stackb, max);
			if (pos <= ft_lenlst(*stackb) / 2)
				rb(stackb);
			else
				rrb(stackb);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		size;
	int		*sortedarr;
	t_stack	*stackb;
	t_stack	*next;

	stackb = NULL;
	stack = ft_parse(ac, av);
	size = ft_lenlst(stack);
	if (!stack)
		return (ft_printf("Error\n"), 0);
	if (is_sorted(stack))
		return (0);
	sortedarr = stack_to_sorted_array(stack, size);
	indexing(&stack, sortedarr, size);
	free(sortedarr);
	ft_buildb(&stack, &stackb);
	ft_build_fromb(&stackb, &stack);
	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	return (0);
}
