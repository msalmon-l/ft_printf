/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:00:29 by msalmon-          #+#    #+#             */
/*   Updated: 2022/05/07 18:36:09 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

int				ft_printf(const char *str, ...);
void			ft_putnbr(int nb);
//int		ft_get_value(const char c, void *str);
int				ft_get_value(const char c, va_list str);
int				ft_putstr(char *str);
void			ft_putnbr_base(int nbr, char *base);
char			*ft_itoa(int n);
int				convert_to_hexa(unsigned long n, char character);
void			*ft_calloc(size_t count, size_t size);
char			*ft_convert_bin(int num);
void			ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *s);
unsigned char		*ft_itoa_unsigned(unsigned int n);

#endif

