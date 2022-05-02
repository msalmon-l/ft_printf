/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:39:09 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/02 18:30:58 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_val(int num, char c);
static int ft_proba(int n, char c);

int	convert_to_hexa(int n, char character)
{
	char	c;
	int		i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	while (n > 16)
	{
		n = ft_proba(n, character);
		i++;
	}
	i++;
	if (n > 9)
	   ft_print_val(n, character);
	else
	{
		c = (n + '0');
		write(1, &c, 1);
	}
	printf("\nel valor devuelto es:%i\n", i);
	return (i);
}

static int ft_proba(int n, char c)
{
	int val;
	val = n % 16;	
//	printf("el resto es=%i\n", val);
	if (val < 10)
	{
		val = val + '0';
		write(1, &val, 1);
	}
	else
		ft_print_val(val, c);
	n /= 16;
//	printf("numero antes de dividir=%i\n", n);
	return (n);
}

static void	ft_print_val(int num, char c)
{
	char x;
//	printf("numero que recibe %i\n para imprimir", num);
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

int main(void)
{
	convert_to_hexa(500, 'x');
}
