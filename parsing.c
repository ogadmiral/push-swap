/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:43:31 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/27 18:13:24 by mdamouh          ###   ########.fr       */
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
		value = to_int(array[i]);
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
		i++;
	}
	return (head);
}

int is_repeated(t_stack *stack)
{
    t_stack *current;
    t_stack *runner;

    current = stack;
    while (current != NULL)
    {
        runner = current->next;
        while (runner != NULL)
        {
            if (current->value == runner->value)
                return (1);
            runner = runner->next;
        }
        current = current->next;
    }
    return (0);
}

t_stack	*ft_single(char	*av)
{
	int		i;
	char	**array;
	t_stack	*stack;

	i = 0;
	while (av[i])
	{
		if ((av[i] <= '9' && av[i] >= '0') || (av[i] > 9 && av[i] < 13)
			|| av[i] == 32)
			i++;
		else
			return (NULL);
	}
	array = ft_split(av, ' ');
	stack = ft_stack(array);
	if (is_repeated(stack))
		return (NULL);
	return (stack);
}

t_stack	*get_numbers(int ac, char **av)
{
	char	**nums;
	int		i;
	t_stack	*stack;
	int	c;

	i = 1;
	while (i < ac)
	{
		c = 0;
		if (ft_isdigit(av[i][c])|| av[i][c] == 32)
			c++;
		else
			return (NULL);
		i++;
	}
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
	i = 0;
	stack = ft_stack(nums);
	if (is_repeated(stack))
		return (NULL);
	return (stack);
}

t_stack	*ft_parse(int ac, char **av)
{
	t_stack	*stacka;

	if (ac == 2)
		stacka = ft_single(av[1]);
	else if(ac > 2)
	{
		stacka = get_numbers(ac, av);
	}
	else
		stacka = NULL;
	return (stacka);
}



