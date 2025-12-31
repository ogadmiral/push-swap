/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:24:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/31 21:48:22 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	ft_applyinst(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line ,"sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line ,"sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line ,"ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line ,"pa\n") == 0)
		pa(b, a);
	else if (ft_strcmp(line ,"pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line ,"ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line ,"rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line ,"rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line ,"rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line ,"rrr\n") == 0)
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
	if(is_sorted(stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
