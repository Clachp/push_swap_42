/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:11:46 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/07 12:03:26 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_long(const char *nptr)
{
	int			i;
	int			s;
	long int	r;

	if (nptr == NULL)
		return (0);
	i = 0;
	s = 1;
	r = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -s;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	if (s * r >= -2147483648 && s * r <= 2147483647)
		return (s * r);
	return (0);
}

int	is_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (*argv[i] != '0' && ft_atoi_long(argv[i]) == 0)
			return (ft_printf("ERROR\n"), 1);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (ft_printf("ERROR\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_double(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;

	first = *stack;
	tmp = (*stack)->next;
	while (first->next)
	{	
		tmp = first->next;
		while (tmp->next)
		{
			if (first->value == tmp->value)
				return (ft_printf("ERROR\n"), 1);
			tmp = tmp->next;
		}
		if (first->value == tmp->value)
			return (ft_printf("ERROR\n"), 1);
		first = first->next;
	}
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	last = ft_lstlast(*stack);
	while (tmp->next && (tmp->value < tmp->next->value))
		tmp = tmp->next;
	if (tmp == last)
		return (1);
	return (0);
}
