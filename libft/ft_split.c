/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:41:12 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/05 00:03:29 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int ft_amount_of_splits(char const *s, char c)
{
    int split_amount;
    int i;

    split_amount = 0;
    i = 0;
    while(s[i])    //contar a quantidade de palavras
    {
        if (s[i] == c)
            split_amount++;
        i++;
        while(s[i] == c)
            i++;
    }
    return (split_amount);
}

static int ft_amount_of_letters(char const *s, char c)
{
    static int i; //uma variavel static e inicializada em 0 se nao for inicializada
    int word_amount;
    
    word_amount = 0;
    
    while (s[i] == c)
        i++;
    while(s[i] && s[i] != c)     // contar a quantidade de letras que cada palavra tendo a variavel
    {                                    // i como static para nao alterar com cada chamada da funcao
        i++;
        word_amount++;
    }
    return (word_amount);
}

static char **ft_do_the_split(char const *s, char c, int split_amount, char **split, int i, int j, int main_string_iterator)
{
    int word_amount;

    while(i < split_amount)
    {
        word_amount = ft_amount_of_letters(s, c) + 1;
        if(!(split[i] = malloc(sizeof(char) * (word_amount + 1)))) // aloja memoria para cada palavra da string
            return (NULL);
        while (j < word_amount)
        {
            while (s[main_string_iterator] == c)
                main_string_iterator++;
            split[i][j++] = (char)s[main_string_iterator];
            main_string_iterator++;
            if(s[main_string_iterator] == c) //  itera um caracter para a frente quando encontra o caracter c, coloca o null
            {                                //  e vai para a proxima palavra, colocando o valor de j, que e o que itera sobre a copia da string,
                main_string_iterator++;      //  a 0, para comecar a proxima palavra do 0
                split[i][j] = '\0';
                j = 0;
                break;
            }
        }
        i++;
    }
    split[i] = NULL;
    return (split);
}

char **ft_split(char const *s, char c)
{
    char **split;
    int split_amount;
    int main_string_iterator;
    int i;
    int j;

    
    j = 0;
    i = 0;
    main_string_iterator = 0;
    split_amount = ft_amount_of_splits(s, c) + 1;
    if(!(split = malloc(sizeof(char*) * (split_amount + 1))))
        return (NULL);
    ft_do_the_split(s, c, split_amount, split, i, j, main_string_iterator);
    free(split);
    return (split);
}
/*
int main(void)
{
    char *str = "     split g   dibfg    dbhsdk     !    ";
    char c = ' ';    
    char **strfinal;
    int i = 0;
    
    strfinal = ft_split(str, c);
    while (i <= ft_amount_of_splits(str, c) + 1)
    {
        printf("%s\n", strfinal[i]);
        i++;
    }
}

split crasha quando:

--> split nao funciona com uma palavra "             olol" c + ' '
--> nao funciona se for separado por \0 
--> if input str == NULL e c = ' ', seg fault ou nao faz return
-->o output de NULL e suposto aparecer??
*/