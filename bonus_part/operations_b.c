/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:20:38 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/05 21:05:13 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	sbbonus(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	(*stack) = second;
}

void	pbbonus(t_stack **stacka, t_stack **stackb)
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
}

void	rbbonus(t_stack **stack)
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
}

void	rrbbonus(t_stack **stack)
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
}
