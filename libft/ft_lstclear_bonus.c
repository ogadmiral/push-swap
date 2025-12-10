/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:34:01 by mdamouh           #+#    #+#             */
/*   Updated: 2025/10/29 10:01:01 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = *lst;
		next = node->next;
		del(node->content);
		free(node);
		*lst = next;
	}
	*lst = NULL;
}
