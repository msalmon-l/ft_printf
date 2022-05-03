/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:44 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/03 20:17:31 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_get_len(int num);
static char	*ft_negative_bin(char *ptr);

char	*ft_convert_bin(int	num)
{
	char	*str;
	int		i;
	int		size;
	int		negative;

	i = 0;
	negative = 0;
	size = ft_get_len(num);
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		negative = 1;
		num *= -1;
	}
	while (size > 0)
	{
		if (num == 1 || num == 0)
			str[size - 1] = num + '0';
		else
			str[size - 1] = (num % 2) + '0';
		num /= 2;
		size--;
	}
	printf("antes del negativo:%s\n", str);
	if (negative == 1)
		str = ft_negative_bin(str);

	printf("\nla cadena es:%s\n", str);
	return (str);
}

static char	*ft_negative_bin(char *ptr)
{
	int	size;
	int n;

	size = ft_strlen(ptr);
	n = size;
	//convertimos a negativo con complemento a 1
	while (size > 0)
	{
		if (ptr[size - 1] == '1')
			ptr[size - 1] = '0';
		else
			ptr[size - 1] = '1';
		
		size--;
	}
	printf("durante el negativo complemento a 1 es:%s\n", ptr);

	//convertivos complemento a 1 en complemento a 2
	// sumando 1 en decimales
	while (n > 0)
	{

		printf("durante el bucle antes del cambio:%c, size es:%i\n", ptr[n - 1], n);
		if (ptr[n - 1] == '1')
			ptr[n - 1] = '0';
		else
		{
			ptr[n - 1] = '1';
			break ;
		}
		printf("durante el bucle despues del cambio:%c, size es:%i\n", ptr[n - 1], n);
		n--;
	}
	printf("cadena dentro del negativo es:%s\n", ptr);
	return (ptr);
}

static int		ft_get_len(int num)
{
	int	n;

	n = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 2; 
		n++;
	}
	return (n);
}

int		main(void)
{
	int val = -1220;
	int x = ft_get_len(val);
	//printf("el tamaño sera:%i", x);
	printf("hexadecimal es:%x\n", val);
	ft_convert_bin(val);
}

