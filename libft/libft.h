/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:36:47 by mdamouh           #+#    #+#             */
/*   Updated: 2026/01/08 10:18:05 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_stack;

// Part 1
char	*ft_strdup(const char *s);
long	ft_atoi(const char *str);
// Part 2
char	**ft_split(char *s);
int		count_words(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		count_total_numbers(int argc, char **argv);
// Bonus
t_stack	*ft_lstnew(int value);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

#endif
