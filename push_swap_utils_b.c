/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:57:06 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/26 10:19:11 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = (*stack);
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	(*stack) = second;
	ft_printf("sb\n");
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*heada;
	t_stack	*headb;
	t_stack	*seconda;

	heada = *stacka;
	headb = *stackb;
	if (!heada)
		return ;
	seconda = (*stacka)->next;
	heada->next = headb;
	*stackb = heada;
	*stacka = seconda;
	ft_printf("pb\n");
}

void	rb(t_stack **stack)
{
	t_stack	*second;
	t_stack	*head;

	head = *stack;
	if (!(*stack) || !(head->next))
		return ;
	second = head->next;
	head->next = NULL;
	*stack = second;
	ft_lstadd_back(stack, head);
	ft_printf("rb\n");
}

int	to_int(const char *s)
{
	int	value;

	value = 0;
	while (*s)
	{
		value = value * 10 + (*s - '0');
		s++;
	}
	return (value);
}

void	rrb(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rra\n");
}
