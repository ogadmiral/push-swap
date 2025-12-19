/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:34:01 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/19 15:09:48 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*node;
	t_stack	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = *lst;
		next = node->next;
		del(node->value);
		free(node);
		*lst = next;
	}
	*lst = NULL;
}
