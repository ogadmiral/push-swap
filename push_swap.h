/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:47:17 by mdamouh           #+#    #+#             */
/*   Updated: 2025/12/30 16:18:26 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void	sb(t_stack **stack);
void	pa(t_stack **stackb, t_stack **stacka);
void	pb(t_stack **stacka, t_stack **stackb);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	sa(t_stack **stack);
t_stack	*ft_parse(int ac, char **av);
int		*stack_to_sorted_array(t_stack *stack, int size);
int		ft_lenlst(t_stack *lst);
void	indexing(t_stack **stack, int	*sorted, int size);
int		get_chunk_size(int size);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
int		ft_isdigit(int c);
int		is_inchunk(int index, int start, int end);
int		count_inchunk(t_stack *stack, int start, int end);
int		get_max(t_stack *stack);
int		is_sorted(t_stack	*a);
int		is_repeated(t_stack *stack);
void	stack_frier(t_stack **stack);
void	small_sort(t_stack *stack, t_stack *stackb, int size);

#endif