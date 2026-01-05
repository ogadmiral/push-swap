/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:43:31 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/05 20:37:58 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack(char	**array)
{
	int		i;
	int		value;
	int		time;
	t_stack	*head;
	t_stack	*node;

	i = 0;
	time = 1;
	while (array[i])
	{
		if (!handle_overflow(array[i]))
			return (NULL);
		value = ft_atoi(array[i++]);
		if (time == 1)
		{
			head = ft_lstnew(value);
			time = 0;
		}
		else
		{
			node = ft_lstnew(value);
			ft_lstadd_back(&head, node);
		}
	}
	return (head);
}

t_stack	*ft_single(char *av)
{
	int		i;
	char	**array;
	t_stack	*stack;

	if (!check_arg(av))
		return (NULL);
	array = ft_split(av, ' ');
	if (!array[0])
		return (free(array), NULL);
	stack = ft_stack(array);
	i = 0;
	while (array[i])
		free(array[i++]);
	if (!stack || is_repeated(stack))
		return (stack_frier(&stack), free(array), NULL);
	return (free(array), stack);
}

t_stack	*nums_to_stack(int ac, char **av)
{
	int		i;
	char	**nums;
	t_stack	*stack;

	nums = malloc(sizeof(char *) * ac);
	if (!nums)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		nums[i - 1] = ft_strdup(av[i]);
		i++;
	}
	nums[i - 1] = NULL;
	stack = ft_stack(nums);
	array_frier(nums);
	if (!stack || is_repeated(stack))
		return (stack_frier(&stack), NULL);
	return (stack);
}

t_stack	*get_numbers(int ac, char **av)
{
	int		i;
	t_stack	*stack;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
			return (NULL);
		while (av[i])
		{
			if (!check_arg(av[i]))
				return (NULL);
			if (is_only_spaces(av[i]))
				return (NULL);
			if (!handle_overflow(av[i]))
				return (NULL);
			i++;
		}
	}
	stack = nums_to_stack(ac, av);
	return (stack);
}

t_stack	*ft_parse(int ac, char **av)
{
	t_stack	*stacka;

	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (NULL);
		stacka = ft_single(av[1]);
	}
	else if (ac > 2)
	{
		stacka = get_numbers(ac, av);
	}
	else
		stacka = NULL;
	return (stacka);
}
