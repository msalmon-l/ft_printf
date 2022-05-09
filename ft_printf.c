/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:52:11 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/07 19:44:38 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_numbers(va_list num, const char c);

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
			write(1, &str[i], 1);
			count++;
		}
	i++;
	}
	va_end(arguments);
	return (count);
}

	//cspdiuxX%
int	ft_get_value(const char c, va_list	str)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	/*if (c == 0)
		return (-1);*/
	if (c == 'c')
		i = ft_putchar(va_arg(str, int));
		//write(1, &(va_arg(str, char)), 1);
	else if (c == 's')
		i = ft_putstr(va_arg(str, char *));
	else if (c == 'p')
		i = convert_to_hexa(va_arg(str, unsigned long), c);
	else if (c == 'x' || c == 'X')
		i = convert_to_hexa(va_arg(str, unsigned int), c);
	else if (c == 'i' || c == 'd' || c == 'u')
		i = ft_print_numbers(str, c);
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

static int	ft_print_numbers(va_list num, const char c)
{
	int				i;
	char			*str;
	
	i = 0;
	str = NULL;
	if (c == 'u')
		str = (char *)ft_itoa_unsigned(va_arg(num, unsigned int));
	else
		str = ft_itoa(va_arg(num, int));
	i = ft_putstr(str);
	free(str);
	return (i);
}
/*
int	main(void)
{
	char *str = malloc(sizeof(char) * 3);
	str[0] = 'h';
	str[1] = 'p';
	str[2] = '\0';
	int a = -500;
	unsigned u = -10;
//	unsigned char b = 'z';
//	double d = 5;
//	printf("%");
	int z = ft_printf("hola %s asdasda %d fin %p %u \n x\n", str, a, &a, u);
	int y = printf("hola %s asdasda %d fin %p %u \n x\n", str, a, &a, u);
	printf("\nMi f=%d caracteres.\nOr f=%d caracteres", z, y);
	printf("\n----------------------------\n");
//	ft_printf("aaa  %  -\n");
//	printf("aaa  %  -\n";

}*/
