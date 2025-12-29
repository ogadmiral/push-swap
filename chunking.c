/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:50:19 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/28 22:28:31 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 50)
		return (17);
	if (size <= 100)
		return (20);
	if (size <= 200)
		return (25);
	if (size <= 300)
		return (30);
	if (size <= 400)
		return (40);
	return (35);
}

void	fill_arr(int *arr, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		arr[i] = start;
		start++;
		i++;
	}
}
