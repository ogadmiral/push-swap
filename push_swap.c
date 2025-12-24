/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:46:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/24 18:45:33 by mdamouh          ###   ########.fr       */
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

#include <stdio.h>
int	find_nearest_pos(t_stack *stack, int size, int start, int end)
{
	int	pos;
	int	best_pos;
	int	best_cost;
	int	cost_up;
	int	cost_down;

	pos = 0;
	best_cost = size + 1;
	while (stack)
	{
		if (stack->index >= start && stack->index <= end)
		{
			cost_up = pos;
			cost_down = size - pos;
			if (cost_up <= cost_down && cost_up < best_cost)
			{
				best_cost = cost_up;
				best_pos = pos;
			}
			else if (cost_down < cost_up && cost_down < best_cost)
			{
				best_cost = cost_down;
				best_pos = -pos;
			}
		}
		stack = stack->next;
		pos++;
	}
	if (best_cost == size + 1)
		return (0);
	return (best_pos);
}

int	is_inrange(t_stack *stack, int start, int end)
{
	while (stack)
	{
		if (stack->index >= start && stack->index <= end)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_sort(int **chunks, int size, t_stack **stacka, t_stack **stackb)
{
	int	chunk_size;
	int	start;
	int	end;
	int	i;
	int	j;
	int	pos;

	chunk_size = get_chunk_size(size);
	start = 0;
	i = 0;
	while (chunks[i])
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		j = 0;
		while (j <= end - start)
		{
			pos = find_nearest_pos(*stacka, ft_lenlst(*stacka), start, end);
			if (pos == 0)
				break;
			if (pos > 0)
				while (pos--)
					ra(stacka);
			else
				while (pos++)
					rra(stacka);
			pb(stacka, stackb);
		}
		start += chunk_size;
		i++;
	}
}

int	ft_getmax(t_stack	*stack)
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
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	rebuildfrom_b(t_stack	**stacka, t_stack	**stackb)
{
	int	max;

	while (*stackb)
	{
		max = ft_getmax(*stackb);
		if ((*stackb)->index == max)
			pa(stackb, stacka);
		else
			rb(stackb);
	}
}

int main(int ac, char **av)
{
	t_stack	*stack;
	int	size;
	int	*sortedarr;
	int	**chunks;
	t_stack	*stackb;

	stack = ft_parse(ac, av);
	size = ft_lenlst(stack);
	if (!stack)
		return (ft_printf("Error\n"), 0);
	sortedarr = stack_to_sorted_array(stack, size);
	indexing(&stack, sortedarr, size);
	chunks = split_into_chunks(size);
	ft_sort(chunks, size, &stack, &stackb);
	rebuildfrom_b(&stack, &stackb);
	return (0);
}
