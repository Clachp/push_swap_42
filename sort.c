/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:07:43 by cchapon           #+#    #+#             */
/*   Updated: 2022/10/06 17:07:54 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		while ((tmp->index == 0 || tmp->index == 1) && ft_lstsize(*a) > 3)
		{
			push_in_stack(a, b, 'b');
			tmp = *a;
		}
		if (ft_lstsize(*a) == 3)
			break ;
		rotate (a, b, 'a');
		tmp = *a;
	}
	sort_three(a, b);
	if ((*b)->next && ((*b)->index < (*b)->next->index))
		swap_stack(a, b, 'b');
	if ((*b)->next)
		push_in_stack(a, b, 'a');
	push_in_stack(a, b, 'a');
}

void	rough_sort(t_stack **a, t_stack **b)
{
	t_stack	*stock;
	int		m;

	m = get_med(a);
	stock = *a;
	while (ft_lstsize(*a) > m)
	{
		stock = *a;
		if (stock->index <= m)
			push_in_stack(a, b, 'b');
		else
			rotate(a, b, 'a');
	}
	stock = *a;
	while (ft_lstsize(*a) > 3)
	{
		stock = *a;
		if (stock->index < get_max(a)->index - 2)
			push_in_stack(a, b, 'b');
		else
			rotate(a, b, 'a');
	}
	sort_three(a, b);
}

void	action_rotate(t_stack *to_sort, t_stack **a, t_stack **b)
{
	int	cost_a;
	int	cost_b;

	cost_a = to_sort->cost_a;
	cost_b = to_sort->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rotate(a, b, 'r');
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rotate(a, b, 'a');
		cost_a--;
	}
	while (cost_b > 0)
	{
		rotate(a, b, 'b');
		cost_b--;
	}
}

void	action_reverse_rotate(t_stack *to_sort, t_stack **a, t_stack **b)
{
	int	cost_a;
	int	cost_b;

	cost_a = to_sort->cost_a;
	cost_b = to_sort->cost_b;
	while (cost_a < 0 && cost_b < 0)
	{
		reverse_rotate(a, b, 'r');
		cost_a++;
		cost_b++;
	}
	while (cost_a < 0)
	{
		reverse_rotate(a, b, 'a');
		cost_a++;
	}
	while (cost_b < 0)
	{
		reverse_rotate(a, b, 'b');
		cost_b++;
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	t_stack	*to_sort;

	if (ft_lstsize(*a) == 5)
		return (sort_five(a, b));
	rough_sort(a, b);
	while (ft_lstsize(*b))
	{
		get_target_pos(a, b);
		to_sort = lowest_cost(a, b);
		action_rotate(to_sort, a, b);
		action_reverse_rotate(to_sort, a, b);
		push_in_stack(a, b, 'a');
	}
	if (is_sorted(a) == 0)
	{
		get_pos(a);
		up_number(a, b, get_min(a)->pos);
	}
}
