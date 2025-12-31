/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:24:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/31 21:12:27 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

void	ft_applyinst(char *line, t_stack **a, t_stack **b)
{
	if (line == "sa\n")
		sa(a);
	else if (line == "sb\n")
		sb(b);
	else if (line == "ss\n")
		ss(a, b);
	else if (line == "pa\n")
		pa(b, a);
	else if (line == "pb\n")
		pb(a, b);
	else if (line == "ra\n")
		ra(a);
	else if (line == "rb\n")
		rb(b);
	else if (line == "rra\n")
		rra(a);
	else if (line == "rrb\n")
		rrb(b);
	else if (line == "rrr\n")
		rrr(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*stackb;
	char	*line;

	stackb = NULL;
	stack = ft_parse(ac, av);
	if (!stack)
	{
		stack_frier(&stack);
		return (write(2, "Error\n", 6), 0);
	}
	if (is_sorted(stack))
		return (stack_frier(&stack), 0);
	line = get_next_line(0);
	while (line)
	{
		ft_applyinst(line, &stack, &stackb);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
