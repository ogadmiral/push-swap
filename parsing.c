/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:43:31 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/08 21:12:17 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atol_strict(char *s, int *out)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		return (0);
	if (!handle_overflow(sign, &result, s + i))
		return (0);
	*out = result * sign;
	return (1);
}

static int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_args(int argc, char **argv, int *k)
{
	int		*numbers;
	char	**split;
	int		i;
	int		j;

	numbers = malloc(sizeof(int) * count_total_numbers(argc, argv));
	if (!numbers)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!count_words(argv[i]))
			return (free(numbers), error_exit(), NULL);
		split = ft_split(argv[i]);
		j = 0;
		while (split[j])
		{
			if (!ft_atol_strict(split[j], &numbers[(*k)++]))
				free_split(split, numbers);
			free(split[j++]);
		}
		free(split);
		i++;
	}
	return (numbers);
}

t_stack	*ft_stack(int *nums, int size)
{
	int		i;
	t_stack	*head;
	t_stack	*node;

	i = 0;
	head = NULL;
	while (i < size)
	{
		node = ft_lstnew(nums[i++]);
		if (!node)
			return (stack_frier(&head), NULL);
		ft_lstadd_back(&head, node);
	}
	return (head);
}

t_stack	*ft_parse(int ac, char **av)
{
	int		*numbers;
	int		size;
	t_stack	*stack;

	size = 0;
	numbers = parse_args(ac, av, &size);
	if (check_duplicates(numbers, size))
		return (free(numbers), NULL);
	stack = ft_stack(numbers, size);
	free(numbers);
	return (stack);
}
