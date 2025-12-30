/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:11:14 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/30 16:26:35 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stackb, t_stack **stacka)
{
	t_stack	*headb;
	t_stack	*heada;
	t_stack	*secondb;

	headb = *stackb;
	heada = *stacka;
	if (!headb)
		return ;
	secondb = (*stackb)->next;
	headb->next = heada;
	*stacka = headb;
	*stackb = secondb;
	ft_printf("pa\n");
}

void	ra(t_stack **stack)
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
	ft_printf("ra\n");
}

void	rra(t_stack **stack)
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

void	sa(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = (*stack);
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	(*stack) = second;
	ft_printf("sa\n");
}
