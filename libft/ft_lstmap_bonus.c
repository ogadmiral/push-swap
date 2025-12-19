/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:05:44 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/19 15:09:48 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_stack	*ft_new(void *value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

static void	ft_delprev(t_stack *lst, void (*del)(void *))
{
	t_stack	*node;
	t_stack	*next;

	while (lst)
	{
		node = lst;
		next = node->next;
		del(lst->value);
		free(node);
		lst = next;
	}
}

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*result;
	t_stack	*new;
	void	*value;

	result = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		value = f(lst->value);
		if (!value)
		{
			ft_delprev(result, del);
			return (NULL);
		}
		new = ft_new(value);
		if (!new)
		{
			ft_delprev(result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
