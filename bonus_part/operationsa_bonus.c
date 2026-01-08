/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsa_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:18:37 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/08 20:49:38 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pabonus(t_stack **stackb, t_stack **stacka)
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
}

void	rabonus(t_stack **stack)
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

void	rrabonus(t_stack **stack)
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

void	sabonus(t_stack **stack)
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
