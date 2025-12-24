/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:50:19 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/24 10:34:12 by mdamouh          ###   ########.fr       */
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
	return (50);
}

// void	fill_arr(int	**arr, int start, int end)
// {
// 	int	i;

// 	i = 0;
// 	while (start < end)
// 	{
// 		*arr[i] = start;
// 		start++;
// 		i++;
// 	}
// }

// int	**split_into_chunks(int size)
// {
// 	int	chunk_size;
// 	int	start;
// 	int	end;
// 	int	**chunks;
// 	int	i;

// 	chunk_size = get_chunk_size(size);
// 	chunks = malloc(size * sizeof(int));
// 	start = 0;
// 	i = 0;
// 	while (start < size)
// 	{
// 		end = start + chunk_size - 1;
// 		if (end >= size)
// 			end = size - 1;
// 		ft_printf("Chunk: [%d - %d]\n", start, end);
// 		chunks[i] = malloc((end - start) * sizeof(int));
// 		fill_arr(&chunks[i], start, end);
// 		i++;
// 		start += chunk_size;
// 	}
// 	return (chunks);
// }

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

int	**split_into_chunks(int size)
{
	int	chunk_size;
	int	start;
	int	end;
	int	**chunks;
	int	i;

	chunk_size = get_chunk_size(size);
	chunks = malloc(((size / chunk_size) + 1) * sizeof(int *));
	if (!chunks)
		return (NULL);
	start = 0;
	i = 0;
	while (start < size)
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		chunks[i] = malloc((end - start + 1) * sizeof(int));
		if (!chunks[i])
			return (NULL);
		fill_arr(chunks[i], start, end);
		i++;
		start += chunk_size;
	}
	chunks[i] = NULL;
	return (chunks);
}
