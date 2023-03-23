/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:22:48 by gfezzuog          #+#    #+#             */
/*   Updated: 2023/03/23 01:41:33 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
int ft_putstr(char *str)
{
	int i;

	i = 0;
	if(!str)
	{
		write(1, "(null)", 6);
		return(6);
	}
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

void ft_putnbr(int n)
{
	if(n == -2147483648)
	{
		ft_putnbr(n/10);
		write(1, "8", 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n/10);
		ft_putchar(48 + n % 10);
	}
}

int countnbr(int n)
{
	int count;
	int nbr;
	count = 0;
	nbr  = n;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			nbr = nbr/10;
			count++;
		}
		nbr *= -1;
		count++;
	}
	while (nbr > 9)
	{
		nbr = nbr/10;
		count++;
	}
	count++;
	ft_putnbr(n);
	return(count);
}

void ft_puthex(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_puthex(nbr/16);
		ft_puthex(nbr%16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
}
int ft_counthex(unsigned int n)
{
	int count;
	int nbr;

	nbr = n;
	count = 0;
	while(nbr != 0)
	{
		count++;
		nbr = nbr/16;
	}
	ft_puthex(n);
	return(count);
}
int ft_printf(const char *str, ...)
{
	int count;
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == '%')
		{
			i++;
			if(str[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if(str[i] == 'x')
				count += ft_counthex(va_arg(args, unsigned int));
			else if (str[i] == 'i')
				count += countnbr(va_arg(args, int));
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	return(count);
}

int main(void)
{
	int i = 48;
	char *c = "CAZZO";

	printf("%i count prinf\n", printf("%s and %i and %x\n", c, i, i));
	ft_printf("%i count ft_printf\n", ft_printf("%s and %i and %x\n", c, i, i));
}