/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:11:04 by gfezzuog          #+#    #+#             */
/*   Updated: 2023/01/02 20:11:04 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int check1(char *argv, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        if (argv[j] == argv[i])
            return (1);
        j++;
    }
    return (0);
}

int check2(char *argv, char c)
{
    int i = 0;
    while (argv[i])
    {
        if (argv[i] == c)
            return(1);
        i++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    int i;

    if(argc != 3)
    {
        write(1, "\n", 1);
        return 0;
    }
    i = 0;
    while (argv[1][i])
    {
        if (!check1(argv[1], i))
            ft_putchar(argv[1][i]);
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        if (!check1(argv[2], 1) && !check2(argv[1], argv[2][i]))
            ft_putchar(argv[2][i]);
        i++;
    }
    write(1, "\n", 1);
    return(0);
}