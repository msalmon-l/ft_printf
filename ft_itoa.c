/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:04:31 by msalmon-          #+#    #+#             */
/*   Updated: 2022/03/04 18:35:05 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_get_len(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	dividir;

	dividir = n;
	i = ft_get_len(dividir) - 1;
	str = malloc(sizeof(char) * (ft_get_len(dividir) + 1));
	if (str == 0)
		return (0);
	if (dividir == -0)
		str[0] = '0';
	else if (dividir < 0)
	{
		str[0] = '-';
		dividir = dividir * -1;
	}
	while (dividir > 0)
	{
		str[i] = (dividir % 10) + '0';
		dividir = dividir / 10;
		i--;
	}
	str[ft_get_len(n)] = '\0';
	return (str);
}

static int	ft_get_len(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (i);
	else if (n > 0)
	{
		while (n >= 10)
		{
			n = n / 10;
			i++;
		}
	}
	else
	{
		while (n <= -10)
		{
			n = n / 10;
			i++;
		}
		i++;
	}
	return (i);
}
