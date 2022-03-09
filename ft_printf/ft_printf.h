/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:15:54 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/09 05:25:21 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	g_i; //mudar depois de entregar
int	g_counter;
int	g_char_counter;

//MAIN EXECUTION
int	ft_printf(char const *format, ...);
int	check(int c);
int	conversion(char c, va_list arg_ptr);

//PRINTERS
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);

//BASE PRINTERS
int	ft_print_unsigned_and_hexa(unsigned int arg_num,
		char *base_string);
int	ft_print_pointeraddress(unsigned long arg_num,
		char *base_string);

#endif
