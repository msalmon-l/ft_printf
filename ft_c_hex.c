/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:39:09 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/09 20:14:05 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_get_len(unsigned long num, char character);
static char	ft_get_character(unsigned long num, char c);

int	convert_to_hexa(unsigned long n, char character)
{
	int		i;
	char	*str;
	int		size;

	i = 0;
	size = ft_get_len(n, character);
	str = calloc(size + 1, sizeof(char));
	while (i < size)
	{
		if (character == 'p' && (size - 1) == i)
			str[size - i - 1] = '0';
		else if (character == 'p' && (size - 2) == i)
			str[size - i - 1] = 'x';
		else if (n < 16)
			str[size - i - 1] = ft_get_character(n, character);
		else
		{
			str[size - i - 1] = ft_get_character((n % 16), character);
			n /= 16;
		}
		i++;
	}
	ft_putstr(str);
	free(str);
	return (i);
}

static int	ft_get_len(unsigned long num, char character)
{
	int	i;

	i = 0;
	if (character == 'p')
		i = 2;
	while (num > 15)
	{
		num /= 16;
		i++;
	}
	if (num >= 0)
		i++;
	return (i);
}

static char	ft_get_character(unsigned long num, char c)
{
	char	x;

	if (num < 10)
		x = num + '0';
	else if (num == 10)
		x = 'a';
	else if (num == 11)
		x = 'b';
	else if (num == 12)
		x = 'c';
	else if (num == 13)
		x = 'd';
	else if (num == 14)
		x = 'e';
	else
		x = 'f';
	if (c == 'X' && num > 9)
		x -= 32;
	return (x);
}

/*
int main(void)
{
	unsigned int x = 32;
	unsigned long z = 32;
	unsigned int *a = &x;

	convert_to_hexa(x, 'x');
	convert_to_hexa(x, 'X');
	convert_to_hexa((unsigned long)&z, 'p');
	printf("\noriginal:\n%x, %X, %p\n", x, x, &z);
	int w = printf("%p", &z);
//	printf("\n%x\n", x);
//	printf("\n%X\n", x);
	printf("la original imprime; %d\n", w);
//	ft_get_len(x, 'p');
}*/
