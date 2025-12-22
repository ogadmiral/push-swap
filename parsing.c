/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:43:31 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/22 18:35:43 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(int ac, char **av)
{
	t_stack	
	if (ac == 2)
	{
		
	}
}

void	ft_single(char	*av)
{
	int	i;
	char	**stack;

	i = 0;
	while (av[i])
	{
		if (!(av[i] < '9' && av[i] > '0') || !(av[i] > 9 && av[i] < 13) || av[i] != 32)
		{
			ft_printf("Error\n");
			return ;
		}
		else
			i++;
	}
	stack = ft_split(av, ' ');
}