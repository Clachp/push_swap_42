/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:07:27 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/07 12:19:41 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_stack(t_stack **a, t_stack **b, char c)
{
	if (c == 'b')
		push_top_on_top(a, b);
	else if (c == 'a')
		push_top_on_top(b, a);
	else
	{
		ft_printf("Wrong char in push_in_stack\n");
		return ;
	}
	ft_printf("p%c\n", c);
}

void	swap_stack(t_stack **a, t_stack **b, char c)
{
	if (!*a && !*b)
		return ;
	if (*a && c == 'a')
		swap_elem(a);
	else if (*b && c == 'b')
		swap_elem(b);
	else
	{
		ft_printf("Wrong char in swap_stack\n");
		return ;
	}
	ft_printf("s%c\n", c);
}

void	swap_both_stacks(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
		return ;
	if (*a)
		swap_elem(a);
	if (*b)
		swap_elem(b);
	ft_printf("ss\n");
}

void	rotate(t_stack **a, t_stack **b, char c)
{
	if (*a && c == 'a')
		top_to_bottom(a);
	else if (*b && c == 'b')
		top_to_bottom(b);
	else if (c == 'r')
	{
		top_to_bottom(a);
		top_to_bottom(b);
	}
	else
	{
		ft_printf("Wrong char in rotate\n");
		return ;
	}
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack **a, t_stack **b, char c)
{
	if (*a && c == 'a')
		bottom_to_top(a);
	else if (*b && c == 'b')
		bottom_to_top(b);
	else if ((*a && *b) && c == 'r')
	{
		bottom_to_top(a);
		bottom_to_top(b);
	}
	else
	{
		ft_printf("Wrong char in reverse_rotate\n");
		return ;
	}
	ft_printf("rr%c\n", c);
}
