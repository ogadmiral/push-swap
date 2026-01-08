/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:43:31 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/08 10:41:59 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol_strict(char *s)
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
		sign = (s[i] == '-') * -1 + (s[i] == '+');
		i++;
	}
	if (!ft_isdigit(s[i]))
		error_exit();
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			error_exit();
		result = result * 10 + (s[i] - '0');
		handle_overflow(sign, result);
		i++;
	}
	return (result * sign);
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
	k = 0;
	while (i < argc)
	{
		if (!count_words(argv[i]))
			error_exit();
		split = ft_split(argv[i]);
		j = 0;
		while (split[j])
		{
			numbers[(*k)++] = (int)ft_atol_strict(split[j]);
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

	numbers = parse_args(ac, av, &size);
	if (check_duplicates(numbers, size))
		return (free(numbers), NULL);
	stack = ft_stack(numbers, size);
	free(numbers);
	return (stack);
}
