/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:00:29 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/09 20:05:57 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(int c);
int				ft_get_value(const char c, va_list str);
int				ft_putstr(char *str);
void			ft_putnbr_base(int nbr, char *base);
char			*ft_itoa(int n);
int				convert_to_hexa(unsigned long n, char character);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
unsigned char	*ft_itoa_unsigned(unsigned int n);

#endif
