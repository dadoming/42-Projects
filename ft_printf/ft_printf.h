/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:15:54 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 16:45:03 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	g_char_counter;

//MAIN EXECUTION
int	ft_printf(char const *format, ...);
int	check_if_in_type(int c);
int	conversion(char c, va_list arg_ptr);

//PRINTERS
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);

//BASE PRINTERS
int	ft_print_unsigned_and_hexa(unsigned int nbr, char *base, int no);
int	ft_print_pointeraddress(unsigned long nbr, char *base, int no);

#endif
