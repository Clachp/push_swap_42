/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:41:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/01 16:01:15 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_puthexa(unsigned long long int n, char x)
{
	char	*base;
	size_t	len;

	len = 0;
	base = "0123456789ABCDEF";
	if (x == 'x')
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_puthexa((n / 16), x);
	len++;
	ft_putchar(base[n % 16]);
	return (len);
}
