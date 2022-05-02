/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:24:07 by msalmon-          #+#    #+#             */
/*   Updated: 2022/03/04 18:18:50 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.c"

void	ft_putnbr_base(int nbr, char *base)
{
	if (!nbr || !base)
		return (0);
	if (ft_memcmp(base, "0123456789", 10) == 0)
		printf(nbr);
	else if (ft_memcmp(base, "01", 2) == 0)
		ft_convert_base();

}

