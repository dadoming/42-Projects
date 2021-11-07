/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:25:03 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/07 14:18:04 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _LIBFT_H_
#define _LIBFT_H_

#include <unistd.h>
#include <stdlib.h>

//BONUS
typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}               t_list;

t_list *ft_lstnew(void *content);                                                           //completo?
void ft_lstadd_front(t_list **lst, t_list *new);                                             //completo?
int ft_lstsize(t_list *lst);                                                                //completo?
t_list *ft_lstlast(t_list *lst);                                                            //completo?
void ft_lstadd_back(t_list **lst, t_list *new);                                             //completo?
void ft_lstdelone(t_list *lst, void (*del)(void*));                                         //completo?
void ft_lstclear(t_list **lst, void (*del)(void*));                                         //completo?
void ft_lstiter(t_list *lst, void (*f)(void *));                                            //completo?
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));                     //verificar!

//PART1
int ft_isalpha(int c);                                                                      //completo!
int ft_isdigit(int c);                                                                      //completo!
int ft_isalnum(int c);                                                                      //completo!
int ft_isascii(int c);                                                                      //completo!
int ft_isprint(int c);                                                                      //completo!
size_t ft_strlen(const char *str);                                                          //completo!
void *ft_memset(void *str, int to_swap, size_t len);                                        //completo!
void ft_bzero(void *str, size_t n);                                                         //completo!
void *ft_memcpy(void *dst, const void *src, size_t n);                                      //completo!
void *ft_memmove(void *dst, const void *src, size_t len);                                   //completo!
size_t ft_strlcpy(char * dst, const char * src, size_t dstsize);                            //completo!
size_t ft_strlcat(char * dst, const char * src, size_t dstsize);                            //completo!
int ft_toupper(int letter);                                                                 //completo!
int ft_tolower(int letter);                                                                 //completo!
char *ft_strchr(const char *str, int c);                                                    //completo!
char *ft_strrchr(const char *str, int c);                                                   //completo!
int ft_strncmp(const char *str1, const char *str2, size_t n);                               //completo!
void *ft_memchr(const void *str, int c, size_t n);                                          //completo!
int ft_memcmp(const void *str1, const void *str2, size_t n);                                //completo!
char *ft_strnstr(const char *str, const char *to_find, size_t len);                         //completo!
int ft_atoi(const char *str);                                                               //completa!

//PART 2
void *ft_calloc(size_t count, size_t size);                                                 //completo!
char *ft_strdup(const char *str);                                                           //NOT / IN DOUBT

//PART 3
char *ft_substr(char const *str, unsigned int start, size_t len);                           //ERRO MALLOC START >= FT_STRLEN(STR)
char *ft_strjoin(const char *s1, const char *s2);                                           //MALLOC NAO PROTEGIDO
char *ft_strtrim(char const *s1, char const *set);                                          //ERRO FULL BLANK
char **ft_split(char const *s, char c);                                                     //MUITOS ERROS
char *ft_itoa(int n);                                                                       //completa!
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));                             //completa!
void ft_striteri(char *s, void (*f)(unsigned int, char*));                                  //completa!
void ft_putchar_fd(char c, int fd);                                                         //completa!
void ft_putstr_fd(char *s, int fd);                                                         //completa!
void ft_putendl_fd(char *s, int fd);                                                        //completa!
void ft_putnbr_fd(int n, int fd);                                                           //completa!

#endif