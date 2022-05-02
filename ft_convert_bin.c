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
static char	*ft_volcar(int num, char *str);

char	*ft_convert_bin(int	num)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = ft_get_len(num);
	str = ft_calloc(size + 1, sizeof(char));
	while (size > 0)
	{
		if (num == 1 || num == 0)
			str[size - 1] = num + '0';
		else
			str[size - 1] = (num % 2) + '0';
		num /= 2;
		size--;
	}
	printf("\nla cadena es:%s\n", str);
	return (str);

}

static int		ft_get_len(int num)
{
	int	n;

	n = 0;
	while (num > 0)
	{
		num /= 2; 
		n++;
	}

	return (n);
}



static char	*ft_volcar(int num, char *str)
{
	return(NULL);
}

int		main(void)
{
	int val = 254;
	int x = ft_get_len(val);
	printf("el tamaño sera:%i", x);
	ft_convert_bin(val);
}

