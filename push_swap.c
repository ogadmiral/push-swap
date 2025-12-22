/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:46:26 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/22 21:40:27 by mdamouh          ###   ########.fr       */
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
int main(int ac, char **av)
{
	t_stack	*stack;

	stack = ft_parse(ac, av);
	ft_printlst(stack, 'a');

	return (0);
}