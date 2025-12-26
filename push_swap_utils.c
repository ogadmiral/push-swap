/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:13:40 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/26 16:58:26 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_inchunk(t_stack *stack, int	**chunks, int size)
{
	int	i;
	int	n;
	int	chunk_size;
	int	start;
	int	end;

	i = 0;
	start = 0;
	chunk_size = get_chunk_size(size);
	while (chunks[i])
	{
		n = 0;
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		while (n < end - start)
		{
			if (stack->index == chunks[i][n])
				reutrn (1);
			n++;
		}
		i++;
		start += chunk_size;
	}
	return (0);
}
