/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:00:29 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/09 20:04:35 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
unsigned char	*ft_itoa_unsigned(unsigned int n);

#endif
