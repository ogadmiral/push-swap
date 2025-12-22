/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:47:17 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/22 21:22:41 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void	ft_printlst(t_stack *stack, char c);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack);
void	pa(t_stack **stackb, t_stack **stacka);
void	pb(t_stack **stacka, t_stack **stackb);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack);
int		to_int(const char *s);
t_stack	*ft_parse(int ac, char **av);

#endif