/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:44 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/02 19:37:01 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_get_len(int num);
static char	*ft_negative_bin(char *ptr, int n);

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
	if (negative == 1)
		str = ft_negative_bin(str, ft_get_len(num));

	printf("\nla cadena es:%s\n", str);
	return (str);
}

static char	*ft_negative_bin(char *ptr, int n)
{
	int	size;

	size = n;
	//convertimos a negativo con complemento a 1
	while (size > 0)
	{
		if (ptr[size - 1] == 1)
			ptr[size - 1] = 0;
		else
			ptr[size - 1] = 1;
		size--;
	}
	//convertivos complemento a 1 en complemento a 2
	// sumando 1 en decimales
	while (n > 0)
	{
		if (ptr[n - 1] == 1)
			ptr[n - 1] = 0;
		else
		{
			ptr[n - 1] = 1;
			break ;
		}
		n--;
	}


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
	int val = -12;
	int x = ft_get_len(val);
	//printf("el tamaño sera:%i", x);
	printf("hexadecimal es:%x\n", val);
	ft_convert_bin(val);
}

