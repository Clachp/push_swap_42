/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:59:54 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/03 11:59:54 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar(char c);
size_t	ft_putnbr(long int n, char flag);
size_t	ft_putstr(char *s);
size_t	ft_puthexa(unsigned long long int n, char flag);
size_t	ft_putptr(unsigned long long int n);
size_t	ft_hexalen(unsigned long long int n);
size_t	ft_strlen(const char *str);
size_t	ft_nbrlen(long int n);

#endif
