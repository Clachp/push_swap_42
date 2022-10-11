/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:08:33 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/01 16:01:21 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_putnbr(long int n, char f)
{
	char		c;
	long int	len;

	if (f == 'u')
		n = (unsigned int)n;
	len = n;
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		c = '0' + n;
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr((n / 10), f);
		ft_putnbr((n % 10), f);
	}
	return (ft_nbrlen(len));
}
