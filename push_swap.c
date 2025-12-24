/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:46:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/24 10:42:40 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_stack *stack, char c)
{
	t_stack *head = stack;
	ft_printf("Stack %c: \n", c);
	while(head)
	{
		ft_printf("%d\n", head->value);
		head = head->next;
	}
}

void	ft_printindex(t_stack *stack, char c)
{
	t_stack *head = stack;
	ft_printf("Stack %c: \n", c);
	while(head)
	{
		ft_printf("%d\n", head->index);
		head = head->next;
	}
}
// int main(void)
// {
// 	int a = 2, b=1, c=3, d=6, e=5, j=8;
// 	t_stack *node1 = ft_lstnew(&a);
// 	t_stack *node2 = ft_lstnew(&b);
// 	t_stack *node3 = ft_lstnew(&c);
// 	t_stack *node4 = ft_lstnew(&d);
// 	t_stack *node5 = ft_lstnew(&e);
// 	t_stack *node6 = ft_lstnew(&j);
// 	t_stack *node1b = NULL;
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;
// 	node4->next = node5;
// 	node5->next = node6;
// 	ft_printlst(node1, 'a');
// 	sa(&node1);
// 	ft_printlst(node1, 'a');
// 	pb(&node1, &node1b);
// 	pb(&node1, &node1b);
// 	pb(&node1, &node1b);
// 	ft_printlst(node1, 'a');
// 	ft_printlst(node1b, 'b');
// 	ra(&node1);
// 	rb(&node1b);
// 	ft_printlst(node1, 'a');
// 	ft_printlst(node1b, 'b');
// }
#include <stdio.h>
void	print_chunks(int **chunks, int size)
{
	int	chunk_size;
	int	start;
	int	end;
	int	i;
	int	j;

	chunk_size = get_chunk_size(size);
	start = 0;
	i = 0;
	while (chunks[i])
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		ft_printf("Chunk %d: ", i);
		j = 0;
		while (j <= end - start)
		{
			ft_printf("%d ", chunks[i][j]);
			j++;
		}
		ft_printf("\n");
		start += chunk_size;
		i++;
	}
}


int main(int ac, char **av)
{
	t_stack	*stack;
	int	size;
	int	*sortedarr;
	int	**chunks;

	stack = ft_parse(ac, av);
	size = ft_lenlst(stack);
	if (!stack)
		return (ft_printf("Error\n"), 0);
	ft_printlst(stack, 'a');
	ft_printf("After indexing: \n");
	sortedarr = stack_to_sorted_array(stack, size);
	indexing(&stack, sortedarr, size);
	ft_printindex(stack, 'a');
	chunks = split_into_chunks(size);
	print_chunks(chunks, size);
	return (0);
}
