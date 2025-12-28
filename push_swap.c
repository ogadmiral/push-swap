/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:46:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/28 10:23:51 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_stack *stack, char c)
{
	t_stack *head = stack;
	ft_printf("Stack %c: \n", c);
	while(head)
	{
		ft_printf("%d\n", head->value);
		head = head->next;
	}
}

void	ft_printindex(t_stack *stack, char c)
{
	t_stack *head = stack;
	ft_printf("Stack %c: \n", c);
	while(head)
	{
		ft_printf("%d\n", head->index);
		head = head->next;
	}
}

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

int	get_position_inchunk(t_stack	*stack, int start, int end)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index <= end && stack->index >= start)
			return (pos);
		else
			pos++;
		stack = stack->next;
	}
	return (pos);
}

void	ft_buildb(t_stack **stacka, t_stack **stackb)
{
	int	size;
	int	chunk_size;
	int	start;
	int	end;
	int	to_push;
	int	pos;

	size = ft_lenlst(*stacka);
	chunk_size = get_chunk_size(size);
	start = 0;

	while (start < size)
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		/* count how many numbers belong to this chunk */
		to_push = count_inchunk(*stacka, start, end);

		while (to_push > 0)
		{
			if (is_inchunk((*stacka)->index, start, end))
			{
				pb(stacka, stackb);
				to_push--;
			}
			else
			{
				pos = get_position_inchunk(*stacka, start, end);
				if (pos <= ft_lenlst(*stacka) / 2)
					ra(stacka);
				else
					rra(stacka);
			}
		}
		start += chunk_size;
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
int main(int ac, char **av)
{
	t_stack	*stack;
	int	size;
	int	*sortedarr;
	t_stack	*stackb;

	stackb = NULL;
	stack = ft_parse(ac, av);
	size = ft_lenlst(stack);
	if (!stack)
		return (ft_printf("Error\n"), 0);
	sortedarr = stack_to_sorted_array(stack, size);
	indexing(&stack, sortedarr, size);
	ft_buildb(&stack, &stackb);
	ft_build_fromb(&stackb, &stack);
	return (0);
}
