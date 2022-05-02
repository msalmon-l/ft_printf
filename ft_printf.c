/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:52:11 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/02 17:16:47 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	i = 0;
	count = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_get_value(str[i + 1], arguments);
			i++;
		}
		else
		{
			//printf("%s%c%s", COLOR_BLUE, str[i], COLOR_RESET);
			write(1, &str[i], 1);
			count++;
		}
	i++;
		
	}
	va_end(arguments);
	return (count);

	
}
/*
void	ft_print_chars(const char *s, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		i++
	}
}*/

int	ft_get_value(const char c, va_list	str)
{
	//cspdiuxX%
	int i;
	char *s;

	s = NULL;
	i = 0;
	if (c == 0)
		return (-1);
	if (c == 'c')
		write(1, &c, 1);
	else if (c == 's')
		i = ft_putstr(va_arg(str, char *));
	else if (c == 'p' || c == 'x' || c == 'X')
		i = convert_to_hexa(va_arg(str, int), c);
	//else if (c == 'd')
	else if (c == 'i' || c == 'd')
	{
		s = ft_itoa(va_arg(str, int));
		i = ft_putstr(s);
		free(s);
	}
	else if (c == 'u')
		printf("x desimal sin signo");
//	else if (c == 'x')
//		i = convert_to_hexa(va_arg(str, int));
//	else if (c == 'X')
//		printf("X");
	else if (c == '%')
		write(1, "%", 1);
		//printf("%s%%%s", COLOR_BLUE, COLOR_RESET);
	//else if (c == ' ')

	return (i);
}

int	main(void)
{
	char *str = malloc(sizeof(char) * 3);
	str[0] = 'h';
	str[1] = 'p';
	str[2] = '\0';
	int a = -500;
	unsigned char b = 'z';
	double d = 5;
//	printf("%");
	int z = ft_printf("hola %s asdasda %d fin %p \n x\n", str, a, a);
	int y = printf("hola %s asdasda %d fin %p \n x\n", str, a, a);
	printf("\nMi f=%d caracteres.\nOr f=%d caracteres", z, y);
/*	printf("hola %p asdasda \n", &a);
	printf("str  %p   sdasda \n", &str);
	printf("p  %p asdasda ", a);
	printf("hola %p asdasda \n", b);
	printf("hola %p asdasda \n", &b);*/
//	printf("%d", d);
}
