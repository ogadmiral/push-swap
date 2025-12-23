/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:08:19 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/23 14:22:11 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lenlst(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	*stack_to_sorted_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	int		j;
	int		tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	indexing(t_stack **stack, int	*sorted, int size)
{
	int	i;
	t_stack	*node;

	i = 0;
	while (i < size)
	{
		node = *stack;
		while (node)
		{
			if (node->value == sorted[i])
			{
				node->index = i;
				break;
			}
			node = node->next;
		}
		i++;
	}
}
