/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:03:27 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/18 10:24:52 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char	*ft_convert(unsigned long n);
int		ft_putchar(int c);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		len(unsigned long n);
int		ft_printhex(unsigned long n);
int		ft_printuphex(unsigned long n);
int		ft_printaddress(unsigned long n);
int		ft_printunsint(unsigned int n);
char	*ft_strcpy(char *dest, const char *src);

#endif
