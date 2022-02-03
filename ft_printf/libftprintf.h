#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

//VER DO MAKEFILE
//VER DO PQ DO CHAR COUNTER ESTAR BEM

#include <stdio.h> //main
#include <unistd.h>
#include <stdarg.h>

int char_counter;

//MAIN EXECUTION
int ft_printf(char const *format, ...);
int check_if_in_type (int c);
int conversion(char c, va_list arg_ptr);

//PRINTERS
int ft_putchar(char c);
int ft_putstr(char *str);
int	ft_putnbr(int n);

//BASE PRINTERS
int	ft_print_unsigned_and_hexa(unsigned int nbr, char *base, int no);
int	ft_print_pointeraddress(unsigned long nbr, char *base, int no);

#endif
