/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:45:55 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/19 14:45:01 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int ft_printchar(int c)
{
    write(1,&c,1);
    return (1);
}

int ft_printstr(char *str)
{
    int i;

    i = 0;
    if (!str)
        i = ft_putstr("(null)");
    else
        i = ft_putstr(str);
    return (i);
}

int ft_putstr(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        write(1,str++,1);
        i++;
    }
    return (i);
}

int ft_printnbr(int n)
{
    
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%d\n",ft_printstr("seckin"));
    return 0;
}
