/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:11:14 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/21 16:00:02 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ss(t_stack **stack)
{
	sa(stack);
	sb(stack);
	ft_printf("ss\n");
}

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

void	rr(t_stack **stack)
{
	ra(stack);
	rb(stack);
	ft_printf("rr\n");
}
