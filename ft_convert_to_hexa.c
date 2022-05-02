/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:39:09 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/02 15:17:43 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_val(int num, char c);

int	convert_to_hexa(int n, char character)
{
	static int		i;
	char	c;

	//i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n <= 16)
	{
		if (n <  10)
		{
			c = (n + '0');
			write(1, &c, 1);
		}
		else
			ft_print_val(n, character);
		i++;
	}
	else
	{
	//	convert_to_hexa(i++);
		convert_to_hexa(n / 16, character);
		convert_to_hexa(n % 16, character);
	}
	//printf("%i\n", i);
	return (i);
}

static void	ft_print_val(int num, char c)
{
	char x;

	if (num == 10)
		x = 'a';
		//write(1, "a", 1);
	else if (num == 11)
		x = 'b';
		//write(1, "b", 1);
	else if (num == 12)
		x = 'c';
		//write(1, "c", 1);
	else if (num == 13)
		x = 'd';
	//write(1, "d", 1);
	else if (num == 14)
		x = 'e';
		//write(1, "e", 1);
	else if (num == 15)
		x = 'f';
		//write(1, "f", 1);
	if (c == 'X')
		x -= 32;
	write(1, &x, 1);
	return ((void)0);
}
/*
int main(void)
{
	convert_to_hexa(500);
}*/
