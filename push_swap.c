/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:46:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/26 15:10:51 by mdamouh          ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_stack	*stack;
	int	size;
	int	*sortedarr;
	//int	**chunks;
	//t_stack	*stackb;

	//stackb = NULL;
	stack = ft_parse(ac, av);
	size = ft_lenlst(stack);
	if (!stack)
		return (ft_printf("Error\n"), 0);
	sortedarr = stack_to_sorted_array(stack, size);
	indexing(&stack, sortedarr, size);
	//chunks = split_into_chunks(size);
	ft_printlst(stack, 'a');
	ft_printindex(stack, 'a');
	return (0);
}
